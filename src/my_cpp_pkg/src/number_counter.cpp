#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"


class NumberCounterNode: public rclcpp::Node 
{
public:
    NumberCounterNode(): Node("number_counter"), counter_(0)
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
            "number", 10,
            std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1)); 

        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);

        server_ = this->create_service<example_interfaces::srv::SetBool>(
            "reset_counter",
            std::bind(&NumberCounterNode::callbackResetCounter, this, std::placeholders::_1, std::placeholders::_2)); // this as the second argument?

        RCLCPP_INFO(this->get_logger(), "Number Counter has been started."); // Print statement
    }

private:
    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg) 
    {
        // Receive the numbers ny subscribing from the /number topic
        counter_ += msg->data;
        RCLCPP_INFO(this->get_logger(), "%d", counter_);

        // Publish the updated count on the /number_count topic
        auto pub_msg = example_interfaces::msg::Int64(); 
        pub_msg.data = counter_;
        publisher_->publish(pub_msg);
    }

    void callbackResetCounter(const example_interfaces::srv::SetBool_Request::SharedPtr request,
                            const example_interfaces::srv::SetBool_Response::SharedPtr response)
    {
        if (request->data) // Check if the boolean data value is set to true
        {
            counter_ = 0;
            response->success = true;
            response->message = "Counter has been reset.";

            // RCLCPP_INFO(this->get_logger(), "Number counter has been reset.");
        }
        else
        {
            response->success = false;
            response->message = "Counter has not been reset.";
        }
    }

    // Declaration of elements
    std::int64_t counter_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr server_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}