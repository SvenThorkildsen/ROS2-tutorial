#include "rclcpp/rclcpp.hpp"

class AddTwoIntsClientNode: public rclcpp::Node
{
public:
    AddTwoIntsClientNode(): Node("cpp_test")
    {
        RCLCPP_INFO(this->get_logger(), "... has been started."); // print statement
    }

private:

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsClientNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}