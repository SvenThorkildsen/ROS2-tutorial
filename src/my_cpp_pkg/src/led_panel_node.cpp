#include "rclcpp/rclcpp.hpp"
// #include "example_interfaces/msg/string.hpp"
#include "my_robot_interfaces/msg/led_status.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"



class LedPanelPublisherNode : public rclcpp::Node 
{
public:
    LedPanelPublisherNode() : Node("led_panel_status_publisher")//, led_states_(3, 0)
    {
        // Declare parameters (and their default values)
        this->declare_parameter("led_states", std::vector<int64_t>{0, 0, 0});
        led_states_ = this->get_parameter("led_states").as_integer_array();

        publisher_ = this->create_publisher<my_robot_interfaces::msg::LedStatus>("led_panel_status", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(4),
                                         std::bind(&LedPanelPublisherNode::publishLedPanelStatus, this));
        set_led_service_ = this->create_service<my_robot_interfaces::srv::SetLed>(
            "set_led",
            std::bind(&LedPanelPublisherNode::callbackSetLed, this, std::placeholders::_1, std::placeholders::_2));
        RCLCPP_INFO(this->get_logger(), "LED Panel Node has been started.");
    }

private:
    void publishLedPanelStatus() 
    {
        // Define format of message
        auto msg = my_robot_interfaces::msg::LedStatus(); 
        
        // Add data to message
        msg.led_status = led_states_; 

        // TODO: Implement functionality to update LED status depending on service messages from the Battery Node
        
        // Publish message
        publisher_->publish(msg);
    }

    void callbackSetLed(const my_robot_interfaces::srv::SetLed::Request::SharedPtr request,
                        const my_robot_interfaces::srv::SetLed::Response::SharedPtr response)
        {
            int64_t led_number = request->led_number;
            int64_t state = request->state;

            if (led_number <= 0 || led_number > 3)
            {
                response->success = false;
                return;
            }
            if (state != 0 && state != 1)
            {
                response->success = false;
                return;
            }

            led_states_.at(led_number -1) = state;
            response->success = true;
            publishLedPanelStatus();
        }

    std::vector<int64_t> led_states_;
    rclcpp::Publisher<my_robot_interfaces::msg::LedStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Service<my_robot_interfaces::srv::SetLed>::SharedPtr set_led_service_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LedPanelPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}