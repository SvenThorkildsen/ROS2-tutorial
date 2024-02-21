#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "my_robot_interfaces/msg/turtle.hpp"
#include "my_robot_interfaces/msg/turtle_array.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include <cmath>

class TurtleControllerNode: public rclcpp::Node
{
    public:
        TurtleControllerNode(): Node("turtle_controller")
        {
            // current_pos_x = 5.5; // Default value in the center of the map
            // current_pos_y = 5.5;
            target_x = 5.5; // Default value in the center of the map
            target_y = 5.5;

            pose_subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
                "turtle1/pose",
                10,
                std::bind(&TurtleControllerNode::callbackTurtlePose, this, std::placeholders::_1));

            turtle_subscriber_ = this->create_subscription<my_robot_interfaces::msg::TurtleArray>(
                "alive_turtles",
                10,
                std::bind(&TurtleControllerNode::callbackFindNextTarget, this, std::placeholders::_1));

            turtle_control_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
                "turtle1/cmd_vel",
                10);
            timer_ = this->create_wall_timer(std::chrono::milliseconds(10),
                                            std::bind(&TurtleControllerNode::publishTurtleController, this));

            RCLCPP_INFO(this->get_logger(), "TurtleControllerNode subcriber has been started.");
        }

    private:
       // Function for updating the current position of the main turtle, this is called whenever the /turtle1/pose topic is updated
        void callbackTurtlePose(const turtlesim::msg::Pose::SharedPtr pose_msg) // TODO: ¿Modify this function to a timer instead of a callback?
        {
            current_pos_x = pose_msg->x;
            current_pos_y = pose_msg->y;
            current_dir = pose_msg->theta;

            // Print line for debugging purposes
            RCLCPP_INFO(this->get_logger(), "Received pose message: x: %f, y: %f, theta: %f, linear velocity: %f, angular velocity: %f",
                    current_pos_x,
                    current_pos_y,
                    pose_msg->theta,
                    pose_msg->linear_velocity,
                    pose_msg->angular_velocity);
        }

        // Function for deciding the next position to move to, this is called whenever the /alive_turtles topic is updated
        void callbackFindNextTarget(const my_robot_interfaces::msg::TurtleArray::SharedPtr turtle_msg)
        {
            RCLCPP_INFO(this->get_logger(), "/alive_turtles has been updated.");

            distance_to_closest_turtle = 15.6; // Variable for storing the current distance to the closest turtle, default value is higher than the diagonal of the map (meaning that it is larger than the distance to any potential turtle)
            std::string name = "None"; // Variable for storing the name of the closest turtle
            float x = 5.544445; // Default value which ensures that the main turtle will return to the middle of the map if there are no other turtles there
            float y = 5.544445; // -----||-----
            

            // Current position of the main turtle is given by the global variables current_pos_x and current_pos_y;
                // These values are calculated in callbackTurtlePose()

            // Obtain the list of potential targets by subscribing to the /alive_turtles topic
                // Then iterate through the list to find the position of the closest turtle
            for (const auto& turtle : turtle_msg->turtles)
            {
                // RCLCPP_INFO(this->get_logger(), "Turtle name: %s",  turtle.name.c_str());
                // RCLCPP_INFO(this->get_logger(), "Turtle pos_x: %f",  turtle.pos_x);
                // RCLCPP_INFO(this->get_logger(), "Turtle pos_y: %f",  turtle.pos_y);

                // Distance from main turtle to the other turtles is found through the Pythagorean theorem
                float distance_to_turtle = sqrt((current_pos_x - turtle.pos_x)*(current_pos_x - turtle.pos_x) + (current_pos_y - turtle.pos_y)*(current_pos_y - turtle.pos_y));
                // RCLCPP_INFO(this->get_logger(), "Distance from main turtle: %f",  distance_to_turtle);

                if (distance_to_turtle < distance_to_closest_turtle)
                {
                    // Update the distance of the closest turtle
                    distance_to_closest_turtle = distance_to_turtle;

                    // Update name of the closest turtle
                    name = turtle.name;

                    // Set the co-ordinates for the updated closest turtle
                    x = turtle.pos_x;
                    y = turtle.pos_y;
                }

            }

            if (name == "None")
            {
                RCLCPP_INFO(this->get_logger(), "There are no turtles on the map, returning to the center.");
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "%s is the closest target. Position: (%f, %f). Distance: %f", name.c_str(), x, y, distance_to_closest_turtle); //TODO: Replace msg->name with the closest turtle's name
            }

            // Return the position of the target
            // return std::make_pair(x, y);
            target_x = x;
            target_y = y;
        }

        // Function for controlling main turtle through a P-regulator, and publishing the 
        void publishTurtleController()
        {
            // Determine value of constant for P-regulator
            // Kp = 0.5; // TODO: ¿Create parameter?

            // Calculate difference between current position of main turtle and its next target
            float error_x = target_x - current_pos_x;
            float error_y = target_y - current_pos_y;
            float error_distance = sqrt(error_x * error_x + error_y * error_y);

            float target_dir = atan2(error_y, error_x); // atan2() computes the angle of the vector between the current position and the target position with regards to which quadrant the solution is located
            float error_dir = target_dir - current_dir;

            // Special case conditions for handling angles greater than ±pi, keeping the angular Twist message in the [-pi, pi] range
            if (error_dir < -M_PI)
            {
                error_dir += 2 * M_PI;
            }
            else if (error_dir > M_PI)
            {
                error_dir -= 2 * M_PI;
            }           


            //Define format of message
            auto msg = geometry_msgs::msg::Twist();

            // Add data to message
            msg.linear.x = 2 * error_distance; // Regulate based on the distance between the main turtle and its target
            // msg.linear.y = Kp * error_y;
            msg.angular.z = 6 * error_dir; // Regulate the direction of the turtle compared to the direction of the target's location

            if (error_distance < 0.2) // Deadzone to reduce oscillations
            {
                msg.linear.x = 0.0;
                msg.angular.z = 0.0;
                RCLCPP_INFO(this->get_logger(), "Target reached!");
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Twist message: Linear(%f, %f, %f), Angular(%f, %f, %f)", msg.linear.x, msg.linear.y, msg.linear.z, msg.angular.x, msg.angular.y, msg.angular.z);
            }

            turtle_control_publisher_->publish(msg);
        }

        float current_pos_x;
        float current_pos_y;
        float current_dir;
        float target_x; // global variable for storing the x-distance to the turtle closest to the main turtle
        float target_y; // -----||-----
        float distance_to_closest_turtle;
        float Kp; // proportional gain constant for P-regulator

        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_subscriber_;
        rclcpp::Subscription<my_robot_interfaces::msg::TurtleArray>::SharedPtr turtle_subscriber_;

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle_control_publisher_;
        rclcpp::TimerBase::SharedPtr timer_;

        // my_robot_interfaces::msg::Turtle closest_turtle;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}