#include "rclcpp/rclcpp.hpp"

class AddTwoIntsClientNode: public rclcpp::Node
{
public:
    AddTwoIntsClientNode(): Node("cpp_test"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello Cpp Node"); // print statement

        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                         std::bind(&AddTwoIntsClientNode::timerCallback, this));
    }

private:

    void timerCallback()
    {
        counter_++;
        RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsClientNode>();
    // auto node = std::make_shared<rclcpp::Node>("cpp_test");
    // RCLCPP_INFO(node->get_logger(), "Hello Cpp Node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}