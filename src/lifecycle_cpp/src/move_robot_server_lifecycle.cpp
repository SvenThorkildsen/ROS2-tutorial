#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "my_robot_interfaces/action/move_robot.hpp"
#include "example_interfaces/msg/string.hpp"

using MoveRobot = my_robot_interfaces::action::MoveRobot;
using MoveRobotGoalHandle = rclcpp_action::ServerGoalHandle<MoveRobot>;
using namespace std::placeholders;
using LifeCycleCallbackReturn =
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;


class MoveRobotServerNode : public rclcpp_lifecycle::LifecycleNode 
{
public:
    MoveRobotServerNode() : LifecycleNode("move_robot_server")
    {
        cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

        current_position_ = 50; // Default position for the robot
        server_activated_ = false;
        robot_name_ = "";

        RCLCPP_INFO(this->get_logger(), "MoveRobotServerNode has been started");
    }


    LifeCycleCallbackReturn on_configure(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        RCLCPP_INFO(this->get_logger(), "IN on_configure");

        this->declare_parameter("robot_name", rclcpp::PARAMETER_STRING);
        robot_name_ = this->get_parameter("robot_name").as_string();

        move_robot_server_ = rclcpp_action::create_server<MoveRobot>(
            this,
            "move_robot_" + robot_name_,
            std::bind(&MoveRobotServerNode::goal_callback, this, _1, _2),
            std::bind(&MoveRobotServerNode::cancel_callback, this, _1),
            std::bind(&MoveRobotServerNode::handle_accepted_callback, this, _1),
            rcl_action_server_get_default_options(),
            cb_group_);

        RCLCPP_INFO(this->get_logger(), "Action server has been configured");
       
        return LifeCycleCallbackReturn::SUCCESS;
    }


    LifeCycleCallbackReturn on_cleanup(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        RCLCPP_INFO(this->get_logger(), "IN on_cleanup");

        this->undeclare_parameter("robot_name");
        robot_name_ = "";
        move_robot_server_.reset();
        // server_activated_ = false;

        return LifeCycleCallbackReturn::SUCCESS;
    }
    

    LifeCycleCallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state)
    {
        RCLCPP_INFO(this->get_logger(), "IN on_activate");

        server_activated_ = true;

        RCLCPP_INFO(this->get_logger(), "Action server has been activated (%d)", current_position_);
 
        rclcpp_lifecycle::LifecycleNode::on_activate(previous_state);
        return LifeCycleCallbackReturn::SUCCESS;
    }


    LifeCycleCallbackReturn on_deactivate(const rclcpp_lifecycle::State &previous_state)
    {
        RCLCPP_INFO(this->get_logger(), "IN on_deactivate");

        server_activated_ = false;

        // Abort goal if node is deactivated
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (goal_handle_)
            {
                if (goal_handle_->is_active())
                {
                    RCLCPP_INFO(this->get_logger(), "Node deactivated - Abort current goal");
                    preempted_goal_id_ = goal_handle_->get_goal_id();
                }
            }
        }

        rclcpp_lifecycle::LifecycleNode::on_deactivate(previous_state);
        return LifeCycleCallbackReturn::SUCCESS;
    }


    LifeCycleCallbackReturn on_shutdown(const rclcpp_lifecycle::State &previous_state)
    {
        (void)previous_state;
        RCLCPP_INFO(this->get_logger(), "IN on_shutdown");

        this->undeclare_parameter("robot_name");
        robot_name_ = "";
        move_robot_server_.reset();
        server_activated_ = false;

        return LifeCycleCallbackReturn::SUCCESS;
    }


    // LifeCycleCallbackReturn on_error(const rclcpp_lifecycle::State &previous_state)
    // {
    //     (void)previous_state;
    //     RCLCPP_INFO(this->get_logger(), "IN on_error");  

    //     move_robot_server_.reset();

    //     // Do some checks to identify the cause of error

    //     return LifeCycleCallbackReturn::FAILURE;
    // }


private:
    rclcpp_action::GoalResponse goal_callback(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const MoveRobot::Goal> goal)
    {
        (void)uuid;

        RCLCPP_INFO(this->get_logger(), "Received a goal");

        // Check if server is active
        if (!server_activated_)
        {
            RCLCPP_WARN(this->get_logger(), "Server not active");
            return rclcpp_action::GoalResponse::REJECT;
        }

        // Check goal validation
        if (goal->position < 0 || goal->position > 100)
        {
            RCLCPP_ERROR(this->get_logger(), "Goal position not valid, rejecting goal.");
            return rclcpp_action::GoalResponse::REJECT;
        }
        if(goal->velocity <= 0)
        {
            RCLCPP_ERROR(this->get_logger(), "Goal velocity not valid, rejecting goal.");
            return rclcpp_action::GoalResponse::REJECT;
        }


        // Policy: preempt existing goal when receiving a new valid goal
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (goal_handle_)
            {
                if (goal_handle_->is_active())
                {
                    RCLCPP_INFO(this->get_logger(), "Abort current goal and accept new goal");
                    preempted_goal_id_ = goal_handle_->get_goal_id();
                }
            }
        }

        
        RCLCPP_INFO(this->get_logger(), "Goal request is valid");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }


    rclcpp_action::CancelResponse cancel_callback(const std::shared_ptr<MoveRobotGoalHandle> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Received cancel request");
        (void)goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }


    void handle_accepted_callback(const std::shared_ptr<MoveRobotGoalHandle> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Goal request accepted");
        execute_goal(goal_handle);
    }


    // Function for executing goal
    void execute_goal(const std::shared_ptr<MoveRobotGoalHandle> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Executing the goal");

        {
            std::lock_guard<std::mutex> lock(mutex_);
            this->goal_handle_ = goal_handle;
        }

        // Get request from goal
        int target_position = goal_handle->get_goal()->position;
        int velocity = goal_handle->get_goal()->velocity;

        // Enable feedback and result messages for client
        auto feedback = std::make_shared<MoveRobot::Feedback>();
        auto result = std::make_shared<MoveRobot::Result>();
        
        // Set loop rate
        rclcpp::Rate loop_rate(1.0);

        // Momentary pause to ensure that the client receives even the first feedback message
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        
        // Execute the action
        while (current_position_ != target_position)
        {
            // Enforce preemption policy
            {
                std::lock_guard<std::mutex> lock(mutex_);
                if (goal_handle->get_goal_id() == preempted_goal_id_)
                {
                    result->position = current_position_;
                    result->message = "Goal was preempted, or node was deactivated";
                    goal_handle->abort(result);
                    return;
                }
            }

            if (goal_handle->is_canceling())
            {
                result->position = current_position_;
                result->message = "Goal was canceled";
                goal_handle->canceled(result);
                return;
            }

            
            // Calculation of the robot's iterative movement
            if (current_position_ < target_position)
            {
                // Move incrementally towards the target position if the target is set higher than the current position
                if (current_position_ + velocity <= target_position)
                {
                    RCLCPP_INFO(this->get_logger(), "Target is still far away (%d)", current_position_);
                    
                    // Move towards the goal with the given velocity
                    current_position_ += velocity;
                }
                else if (current_position_ + velocity > target_position)
                {
                    RCLCPP_INFO(this->get_logger(), "Target is close (%d)", current_position_);           

                    // If the robot is closer to the target than the given velocity, move with a speed equal to the remaining distance
                    current_position_ += target_position - current_position_;
                }
            }
            // Move in the negative direction if the goal is set lower than the current position
            else if (current_position_ > target_position)
            {
                if (current_position_ - velocity >= target_position)
                {
                    RCLCPP_INFO(this->get_logger(), "Target is still far away (%d)", current_position_);
                    current_position_ -= velocity;
                }
                else if (current_position_ - velocity < target_position)
                {
                    RCLCPP_INFO(this->get_logger(), "Target is close (%d)", current_position_);
                    current_position_ += target_position - current_position_;
                }
            }

            feedback->current_position = current_position_;
            goal_handle->publish_feedback(feedback);
            loop_rate.sleep();
        }

        RCLCPP_INFO(this->get_logger(), "Target reached!");

        // Set final state and return result
        result->position = current_position_;
        result->message = "This is a test message";
        goal_handle->succeed(result);
    }


    rclcpp_action::Server<MoveRobot>::SharedPtr move_robot_server_;
    rclcpp::CallbackGroup::SharedPtr cb_group_;
    std::mutex mutex_;
    std::shared_ptr<MoveRobotGoalHandle> goal_handle_;
    rclcpp_action::GoalUUID preempted_goal_id_;
    int current_position_;

    std::string robot_name_;
    bool server_activated_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MoveRobotServerNode>(); 
    // rclcpp::spin(node);
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node->get_node_base_interface());
    executor.spin();
    rclcpp::shutdown();
    return 0;
}