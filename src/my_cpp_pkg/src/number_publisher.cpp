#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"


class NumberPublisherNode : public rclcpp::Node //TODO (Ex: NumberPublisherNode)
{
public:
    NumberPublisherNode() : Node("number_publisher"), number_(2) //TODO (Ex: number_publisher)
    {
        // Declare parameters
        this->declare_parameter("name");

        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10); //TODO (Ex: number)
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                         std::bind(&NumberPublisherNode::publishNumber, this));

        RCLCPP_INFO(this->get_logger(), "Publisher has been started.");
    }

private:
    void publishNumber() //TODO (Ex: publishNumber)
    {
        auto msg = example_interfaces::msg::Int64(); //TODO: DEFINE FORMAT OF MESSAGE (Ex: String, Int64...)
        msg.data = number_; //TODO: ADD DATA TO MESSAGE
        publisher_->publish(msg);
    }

    std::int64_t number_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}