#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class TurtleControllerNode: public rclcpp::Node
{
    public:
        TurtleControllerNode(): Node("turtle_controller")
        {
            pose_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(
                "turtle1/pose", 10,
                std::bind(&TurtleControllerNode::callbackTurtlePose, this, std::placeholders::_1));
            RCLCPP_INFO(this->get_logger(), "TurtleControllerNode subcriber has been started.");
        }

    private:
        void callbackTurtlePose(const geometry_msgs::msg::Twist::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "Received pose message: Linear (%f, %f, %f), Angular (%f, %f, %f)",
                    msg->linear.x, msg->linear.y, msg->linear.z,
                    msg->angular.x, msg->angular.y, msg->angular.z);
        }

        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr pose_subscriber_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleControllerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}