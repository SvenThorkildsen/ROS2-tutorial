#include "rclcpp/rclcpp.hpp"
// #include "example_interfaces/srv/add_two_ints.hpp"
#include "my_robot_interfaces/srv/set_led.hpp"

using std::placeholders::_1;
using std::placeholders::_2;


class BatteryNode: public rclcpp::Node
{
public:
    BatteryNode(): Node("battery"), battery_state_(false) 
    {
        // server_ = this->create_service<my_robot_interfaces::srv::SetLed>(
        //     "set_led",
        //     std::bind(&BatteryNode::callbackSetLed, this, _1, _2)); // _1 and _2 are placeholders for the request and response fields

        last_time_battery_state_changed_ = this->get_clock()->now().seconds();

        battery_timer_ = this->create_wall_timer(
                std::chrono::milliseconds(100),
                std::bind(&BatteryNode::checkBatteryState, this));

        RCLCPP_INFO(this->get_logger(), "Battery node has been started."); // print statement
    }

private:
    void setLed(int led_number, int state)
    {
        threads_.push_back(std::thread(std::bind(&BatteryNode::callSetLedService, this, led_number, state)));
    }


    void callSetLedService(int led_number, int state) 
    {
        auto client = this->create_client<my_robot_interfaces::srv::SetLed>("set_led");
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for the server to be up...");
        }

        auto request = std::make_shared<my_robot_interfaces::srv::SetLed::Request>();
        request->led_number = led_number;
        request->state = state;

        auto future = client->async_send_request(request);

        try
        {
            auto response = future.get();
            // RCLCPP_INFO(this->get_logger(), "");
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }
    }    
        
        
        
    void checkBatteryState()
    {        
        double time_now = this->get_clock()->now().seconds();

        if (battery_state_)
        {
            if (time_now - last_time_battery_state_changed_ > 4.0)
            {
                // Turn LED ON  
                setLed(3,1);
                RCLCPP_INFO(this->get_logger(), "Battery low - turn LED ON.");
                battery_state_ = !battery_state_;
                last_time_battery_state_changed_ = time_now;
            }
        }
        else
        {
            if (time_now - last_time_battery_state_changed_ > 6.0)
            {
                // Turn led OFF
                setLed(3,0);
                RCLCPP_INFO(this->get_logger(), "Battery high - turn LED OFF.");
                battery_state_ = !battery_state_;
                last_time_battery_state_changed_ = time_now;
            }
        }
    }


    bool battery_state_;
    double last_time_battery_state_changed_;

    std::vector<std::thread> threads_;
    rclcpp::TimerBase::SharedPtr battery_timer_;
    // rclcpp::Service<my_robot_interfaces::srv::SetLed>::SharedPtr server_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BatteryNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}