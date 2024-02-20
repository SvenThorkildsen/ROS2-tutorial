#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
#include "my_robot_interfaces/msg/turtle.hpp"
#include "my_robot_interfaces/msg/turtle_array.hpp"

class TurtleControllerNode: public rclcpp::Node
{
    public:
        TurtleControllerNode(): Node("turtle_controller")
        {
            pose_subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
                "turtle1/pose",
                10,
                std::bind(&TurtleControllerNode::callbackTurtlePose, this, std::placeholders::_1));

            turtle_subscriber_ = this->create_subscription<my_robot_interfaces::msg::TurtleArray>(
                "alive_turtles",
                10,
                std::bind(&TurtleControllerNode::callbackFindNextTarget, this, std::placeholders::_1));

            RCLCPP_INFO(this->get_logger(), "TurtleControllerNode subcriber has been started.");
        }

    private:
        void callbackTurtlePose(const turtlesim::msg::Pose::SharedPtr pose_msg) // TODO: ¿Modify this function to a timer instead of a callback?
        {
            current_pos_x = pose_msg->x;
            current_pos_y = pose_msg->y;

            RCLCPP_INFO(this->get_logger(), "Received pose message: x: %f, y: %f, theta: %f, linear velocity: %f, angular velocity: %f",
                    current_pos_x,
                    current_pos_y,
                    pose_msg->theta,
                    pose_msg->linear_velocity,
                    pose_msg->angular_velocity);
        }

        // Function for deciding the next position to move to
        std::pair<int, int> callbackFindNextTarget(const my_robot_interfaces::msg::TurtleArray::SharedPtr turtle_msg)
        {
            RCLCPP_INFO(this->get_logger(), "/alive_turtles has been updated.");

            std::string name;
            int x, y;

            // Current position of the main turtle is given by the global variables current_pos_x and current_pos_y;

            // Obtain the list of potential targets by subscribing to the /alive_turtles topic
            for (const auto& turtle : turtle_msg->turtles)
            {
                name = turtle.name;
                RCLCPP_INFO(this->get_logger(), "Turtle name: %s", name.c_str());
            }
                



            // RCLCPP_INFO(this->get_logger(), "%s is the closest target.", msg->name.c_str()); //TODO: Replace msg->name with the closest turtle's name

            // Determine which target is the closest
                // Iterate through the list of potential targets, compare distance to current position
            x = 2.0;
            y = 3.0;

            // Return the position of the target
            return std::make_pair(x, y);
        }

        float current_pos_x;
        float current_pos_y;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_subscriber_;
        rclcpp::Subscription<my_robot_interfaces::msg::TurtleArray>::SharedPtr turtle_subscriber_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}