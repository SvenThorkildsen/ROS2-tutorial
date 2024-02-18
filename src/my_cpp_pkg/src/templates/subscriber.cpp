#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class SubscriberNode: public rclcpp::Node //TODO (Ex: SmartphoneNode)
{
public:
    SubscriberNode(): Node("[NODE NAME]") //TODO (Ex: smartphone)
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::String>(
            "[TOPIC NAME]", 10,
            std::bind(&SubscriberNode::callbackFunction, this, std::placeholders::_1)); // TODO: topic name and callback function (Ex: robot_news, callbackRobotNews)

        RCLCPP_INFO(this->get_logger(), "Subcriber has been started."); // Print statement
    }

private:
    void callbackFunction(const example_interfaces::msg::String::SharedPtr msg) //TODO (Ex: callbackRobotNews)
    {
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }

    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscriberNode>(); //TODO (Ex: SmartphoneNode)
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}