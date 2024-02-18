#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"


class PublisherNode : public rclcpp::Node //TODO (Ex: NumberPublisherNode)
{
public:
    PublisherNode() : Node("[NODE NAME]") //TODO (Ex: number_publisher)
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("[TOPIC NAME]", 10); //TODO (Ex: number)
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                         std::bind(&PublisherNode::publishFunction, this)); //TODO (Ex: publishHardwareStatus)
        RCLCPP_INFO(this->get_logger(), "Publisher has been started.");
    }

private:
    void publishFunction() //TODO
    {
        // DEFINE FORMAT OF MESSAGE
        auto msg = example_interfaces::msg::String(); //TODO (Ex: String, Int64...)
        
        // ADD DATA TO MESSAGE
        msg.data = std::string("Hi, this is a message from the publisher."); 
        publisher_->publish(msg);
    }

    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}