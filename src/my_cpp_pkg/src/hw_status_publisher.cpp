#include "rclcpp/rclcpp.hpp"
// #include "example_interfaces/msg/string.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"



class HardwareStatusPublisherNode : public rclcpp::Node 
{
public:
    HardwareStatusPublisherNode() : Node("hardware_status_publisher") 
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_status", 10); 
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
                                         std::bind(&HardwareStatusPublisherNode::publishHardwareStatus, this));
        RCLCPP_INFO(this->get_logger(), "Publisher has been started.");
    }

private:
    void publishHardwareStatus()
    {
        // DEFINE FORMAT OF MESSAGE 
        auto msg = my_robot_interfaces::msg::HardwareStatus();

        // Add data to message fields
        msg.temperature = 42;
        msg.are_motors_ready = false;
        msg.debug_message = "Debug message.";

        // Publish message 
        publisher_->publish(msg);
    }

    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}