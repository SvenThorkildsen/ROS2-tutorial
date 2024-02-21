#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/turtle.hpp"
#include "my_robot_interfaces/msg/turtle_array.hpp"
#include "turtlesim/srv/spawn.hpp"

#include <cstdlib> // for rand() and RAND_MAX


class TurtleSpawnerNode : public rclcpp::Node 
{
public:
    TurtleSpawnerNode() : Node("turtle_spawner")
    {
        // Initialise default turtle
        // turtles_ = (5, {"default_name", 2.3, 4.5});
        default_turtle.name = "default_name";
        default_turtle.pos_x = 1.0;
        default_turtle.pos_y = 1.0;

        test_turtle.name = "test_turtle";
        test_turtle.pos_x = 8.544445;
        test_turtle.pos_y = 9.544445;

        // Add the default turtle to the TurtleArray
        // turtles_.turtles.push_back(default_turtle);

        publisher_ = this->create_publisher<my_robot_interfaces::msg::TurtleArray>(
            "alive_turtles", 
            10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(2000),
                                         std::bind(&TurtleSpawnerNode::publishTurtleArray, this)); 


        RCLCPP_INFO(this->get_logger(), "Publisher has been started.");
    }

private:
    void publishTurtleArray() //TODO
    {
        // DEFINE FORMAT OF MESSAGE
        auto msg = my_robot_interfaces::msg::TurtleArray();
        
        // ADD DATA TO MESSAGE
        // msg.turtles = turtles_;
        msg.turtles.push_back(default_turtle);
        msg.turtles.push_back(test_turtle);

        // Publish list of turtles on the /alive_turtles topic
        publisher_->publish(msg);
    }

    // void callSpawnService()
    // {
    //     // Call the /spawn service to create a new turtle

    //     auto client = this->create_client<turtlesim::srv::Spawn>("spawn");
    //     while (!client->wait_for_service(std::chrono::seconds(1)))
    //     {
    //         RCLCPP_WARN(this->get_logger(), "Waiting for the spawn-server to be up...");
    //     }

    //     auto request = std::make_shared<turtlesim::srv::Spawn::Request>();

    //     // Set random values between 1.0 - 11.0 for the x and y position
    //     request->x = generateRandomFloat32(1.0f, 11.0f);
    //     request->y = generateRandomFloat32(1.0f, 11.0f);

    //     // Set random value for theta within 
    //         //TODO: Test 3.14f
    //     request->theta = generateRandomFloat32(0.0f, 3.1f);


    //     auto future = client->async_send_request(request);
    //     try
    //     {
    //         auto response = future.get();
    //         // RCLCPP_INFO(this->get_logger(), "");
    //     }
    //     catch (const std::exception &e)
    //     {
    //         RCLCPP_ERROR(this->get_logger(), "Service call failed");
    //     }

    // }

    // Function for generating a random float32 within a range
    float generateRandomFloat32(float min, float max)
    {
        // TODO: ¿call srand() to seed the random generator with a unique value?
            // This would ensure that the same sequence of generated numbers does not occurr every time

        // Generate a random integer between 0 and RAND_MAX
        int random_int = rand();

        // Scale and shift the random integer to the desired range
        float random_float = min + static_cast<float>(random_int) / RAND_MAX * (max - min);

        return random_float;
    }

    rclcpp::Publisher<my_robot_interfaces::msg::TurtleArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    // my_robot_interfaces::msg::TurtleArray turtles_;
    my_robot_interfaces::msg::Turtle default_turtle;
    my_robot_interfaces::msg::Turtle test_turtle;
    

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleSpawnerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}