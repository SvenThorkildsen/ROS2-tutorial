#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/turtle.hpp"
#include "my_robot_interfaces/msg/turtle_array.hpp"
#include "my_robot_interfaces/srv/catch_turtle.hpp"
#include "turtlesim/srv/kill.hpp"
#include "turtlesim/srv/spawn.hpp"


#include <cmath>
#include <cstdlib> // for rand() and RAND_MAX



class TurtleSpawnerNode : public rclcpp::Node 
{
public:
    TurtleSpawnerNode() : Node("turtle_spawner")
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::TurtleArray>(
            "alive_turtles", 
            10);
        publisher_timer_ = this->create_wall_timer(std::chrono::milliseconds(100),
                                                   std::bind(&TurtleSpawnerNode::publishTurtleArray, this)); 

        RCLCPP_INFO(this->get_logger(), "Publisher has been started.");

        spawn_timer_ = this->create_wall_timer(std::chrono::milliseconds(3000),
                                               std::bind(&TurtleSpawnerNode::spawnTurtle, this));

        catch_turtle_service_ = this->create_service<my_robot_interfaces::srv::CatchTurtle>(
            "catch_turtle",
            std::bind(&TurtleSpawnerNode::callbackCatchTurtle, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    void publishTurtleArray() //TODO
    {
        // DEFINE FORMAT OF MESSAGE
        auto msg = my_robot_interfaces::msg::TurtleArray();
        
        // ADD DATA TO MESSAGE
        msg.turtles = alive_turtles_;

        // Publish list of turtles on the /alive_turtles topic
        publisher_->publish(msg);
        // RCLCPP_INFO(this->get_logger(), "/alive_turtles has been updated.");
    }

    void spawnTurtle()
    {
        // Set random values between 0.0 - 11.0 for the x and y position
        float x =  generateRandomFloat32(0.0f, 11.0f);
        float y =  generateRandomFloat32(0.0f, 10.0f);
        float theta = generateRandomFloat32(0.0f, 2 * M_PI); // ¿Range from [-pi, pi] or [0, 2 * M_PI]?

        spawn_turtle_threads_.push_back(
            std::make_shared<std::thread>(
                std::bind(&TurtleSpawnerNode::callSpawnService, this, x, y, theta)));
    }

    void callSpawnService(float x, float y, float theta)
    {
        // Call the /spawn service to create a new turtle

        RCLCPP_INFO(this->get_logger(), "/spawn service has been called.");

        auto client = this->create_client<turtlesim::srv::Spawn>("spawn");
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for the spawn-server to be up...");
        }

        auto request = std::make_shared<turtlesim::srv::Spawn::Request>();

        request->x = x;
        request->y = y;
        request->theta = theta;

        auto future = client->async_send_request(request);

        try
        {
            auto response = future.get();
            std::string name = response->name;
            RCLCPP_INFO(this->get_logger(), "%s spawned at (%f, %f)", name.c_str(), x, y);

            if (name != "")
            {
                auto new_turtle = my_robot_interfaces::msg::Turtle();
                new_turtle.name = name;
                new_turtle.pos_x = x;
                new_turtle.pos_y = y;
                // new_turtle.theta = theta;

                // Add turtle to array of alive turtles
                alive_turtles_.push_back(new_turtle);
            }
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }

        // TODO: ¿Call publish function?
    }

    void callbackCatchTurtle(const my_robot_interfaces::srv::CatchTurtle::Request::SharedPtr request,
                             const my_robot_interfaces::srv::CatchTurtle::Response::SharedPtr response)
    {
        // Retrieve information from the request
        std::string name = request->name;

        // Call service
        kill_turtle_threads_.push_back(
            std::make_shared<std::thread>(
                std::bind(&TurtleSpawnerNode::callKillTurtleService, this, name)));
        
        // Add service response
        response->success = true;
    }

    void callKillTurtleService(std::string turtle_name)
    {
        auto client = this->create_client<turtlesim::srv::Kill>("kill");
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for the spawn-server to be up...");
        }

        auto request = std::make_shared<turtlesim::srv::Kill::Request>();

        request->name = turtle_name;

        auto future = client->async_send_request(request);

        try
        {
            auto response = future.get();

            // Remove turtle from /alive_turtles
            printArray(alive_turtles_);
            removeTurtleByName(alive_turtles_, turtle_name);
            printArray(alive_turtles_);
            
            // RCLCPP_INFO(this->get_logger(), "");
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }        
    }

    void removeTurtleByName(std::vector<my_robot_interfaces::msg::Turtle>& array, const std::string& name)
    {
        for (size_t i = 0; i < array.size(); ++i)
        {
            if (array.at(i).name == name)
            {
                array.erase(array.begin() + i);
                RCLCPP_INFO(this->get_logger(), "%s has been removed", name.c_str());
                
                // Publish /alive_turtles
                publishTurtleArray();
                break; // Exit the loop since the turtle has been found and removed
            }
        }
    }

    void printArray(std::vector<my_robot_interfaces::msg::Turtle> array)
    {
        for (const auto &element : array)
            {
                // Extract the tuple elements
                const auto &[str, float1, float2] = element;

                // Print each element using RCLCPP_INFO
                RCLCPP_INFO(this->get_logger(), "String: %s, Float 1: %.2f, Float 2: %.2f", str.c_str(), float1, float2);
            }
    }

    // Function for generating a random float32 within a range
    float generateRandomFloat32(float min, float max)
    {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

        // Generate a random integer between 0 and RAND_MAX
        int random_int = rand();

        // Scale and shift the random integer to the desired range
        float random_float = min + static_cast<float>(random_int) / RAND_MAX * (max - min);

        return random_float;
    }

    rclcpp::Publisher<my_robot_interfaces::msg::TurtleArray>::SharedPtr publisher_;
    
    rclcpp::TimerBase::SharedPtr publisher_timer_;
    rclcpp::TimerBase::SharedPtr spawn_timer_;

    std::vector<my_robot_interfaces::msg::Turtle> alive_turtles_;
    
    std::vector<std::shared_ptr<std::thread>> spawn_turtle_threads_;
    std::vector<std::shared_ptr<std::thread>> kill_turtle_threads_;

    rclcpp::Service<my_robot_interfaces::srv::CatchTurtle>::SharedPtr catch_turtle_service_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleSpawnerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}