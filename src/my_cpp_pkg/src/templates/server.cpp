#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

using std::placeholders::_1;
using std::placeholders::_2;


class ServerNode: public rclcpp::Node //TODO (Ex: AddTwoIntsServerNode)
{
public:
    ServerNode(): Node("[SERVER NAME]") //TODO (Ex: add_two_ints_server)
    {
        server_ = this->create_service<example_interfaces::srv::AddTwoInts>(
            "[SERVICE NAME]",
            std::bind(&ServerNode::callbackFunction, this, _1, _2)); // _1 and _2 are placeholders //TODO (Ex: add_two_ints)


        RCLCPP_INFO(this->get_logger(), "Add Two Ints Server has been started."); // print statement
    }

private:
    void callbackFunction(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                            const example_interfaces::srv::AddTwoInts::Response::SharedPtr response) //TODO (Ex: callbackAddTwoInts)
    {
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "%d + %d = %d", request->a, request->b, response->sum);
    }


    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ServerNode>(); //TODO (Ex: AddTwoIntsServerNode)
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}