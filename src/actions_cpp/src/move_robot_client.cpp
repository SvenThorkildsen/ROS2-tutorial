#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_robot_interfaces/action/move_robot.hpp"
#include "example_interfaces/msg/string.hpp"

using MoveRobot = my_robot_interfaces::action::MoveRobot;
using MoveRobotGoalHandle = rclcpp_action::ClientGoalHandle<MoveRobot>;
using namespace std::placeholders;

class MoveRobotClientNode : public rclcpp::Node 
{
public:
    MoveRobotClientNode() : Node("move_robot_client") 
    {
        move_robot_client_ =
            rclcpp_action::create_client<MoveRobot>(this, "move_robot");

        cancel_subscriber_ = this->create_subscription<example_interfaces::msg::String>(
            "cancel_move",
            10,
            std::bind(&MoveRobotClientNode::cancel_callback, this, _1));
        
        RCLCPP_INFO(this->get_logger(), "Client node started.");
    }


    void send_goal(int target_position, int velocity)
    {
        // Wait for action server
        move_robot_client_->wait_for_action_server();

        // Create goal
        auto goal = MoveRobot::Goal();
        goal.position = target_position;
        goal.velocity = velocity;

        // Add callbacks
        auto options = rclcpp_action::Client<MoveRobot>::SendGoalOptions();
        options.result_callback =
            std::bind(&MoveRobotClientNode::goal_result_callback, this, _1);
        options.goal_response_callback = 
            std::bind(&MoveRobotClientNode::goal_response_callback, this, _1);
        options.feedback_callback =
            std::bind(&MoveRobotClientNode::goal_feedback_callback, this, _1, _2);


        // Send the goal
        RCLCPP_INFO(this->get_logger(), "Sending a goal");
        move_robot_client_->async_send_goal(goal, options);
    }


private:
    void goal_response_callback(const MoveRobotGoalHandle::SharedPtr &goal_handle)
    {
        if (!goal_handle)
        {
            RCLCPP_WARN(this->get_logger(), "Goal got rejected");
        }
        else
        {
            this->goal_handle_ = goal_handle;
            RCLCPP_INFO(this->get_logger(), "Goal got accepted");
        }
    }


    // Callback to receive the result once the goal is done
    void goal_result_callback(const MoveRobotGoalHandle::WrappedResult &result)
    {
        auto status = result.code;
        if (status == rclcpp_action::ResultCode::SUCCEEDED)
        {
            RCLCPP_INFO(this->get_logger(), "Succeeded");
        }
        else if (status == rclcpp_action::ResultCode::ABORTED)
        {
            RCLCPP_ERROR(this->get_logger(), "Aborted");
        }
        else if (status == rclcpp_action::ResultCode::CANCELED)
        {
            RCLCPP_WARN(this->get_logger(), "Canceled");
        }

        int position = result.result->position;
        RCLCPP_INFO(this->get_logger(), "Result: %d", position);
    }


    void goal_feedback_callback(const MoveRobotGoalHandle::SharedPtr &goal_handle,
                                const std::shared_ptr<const MoveRobot::Feedback> feedback)
    {
        (void)goal_handle;

        int position = feedback->current_position;
        RCLCPP_INFO(this->get_logger(), "Got feedback: %d", position);
    }


    // Cancel goal if a message is received on the /cancel_move topic
    void cancel_callback(const example_interfaces::msg::String msg)
    {
        (void)msg; // The content of the message is not of importance
        if (this->goal_handle_)
        {
            this->move_robot_client_->async_cancel_goal(goal_handle_);
            goal_handle_.reset();
        }
    }
    
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr cancel_subscriber_;
    rclcpp_action::Client<MoveRobot>::SharedPtr move_robot_client_;
    MoveRobotGoalHandle::SharedPtr goal_handle_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MoveRobotClientNode>();
    node->send_goal(97, 2);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}