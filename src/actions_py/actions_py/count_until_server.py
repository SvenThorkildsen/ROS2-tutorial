#!/usr/bin/env python3
import rclpy
import time
import threading
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle, GoalResponse, CancelResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from my_robot_interfaces.action import CountUntil



class CountUntilServerNode(Node):
    def __init__(self):
        super().__init__("count_until_server") 
        self.goal_handle_: ServerGoalHandle = None
        self.goal_lock_ = threading.Lock()
        self.count_until_server_ = ActionServer(
            self,
            CountUntil,
            "count_until",
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
            callback_group=ReentrantCallbackGroup())
        self.get_logger().info("Action server has been started")


    def goal_callback(self, goal_request: CountUntil.Goal):
        self.get_logger().info("Received a goal")

        # Policy: refuse new goal if current goal is still active
        if self.goal_handle_ is not None and self.goal_handle_.is_active:
            self.get_logger().info("Goal is already active, rejecting new goal")
            return GoalResponse.REJECT
        
        # Validate the goal request
        if goal_request.target_number <= 0:
            self.get_logger().info("Rejecting the goal")
            return GoalResponse.REJECT
        self.get_logger().info("Accepting the goal")
        return GoalResponse.ACCEPT
    
    
    def cancel_callback(self, goal_handle: ServerGoalHandle):
        self.get_logger().info("Received a cancel request")
        return CancelResponse.ACCEPT # or REJECT


    def execute_callback(self, goal_handle: ServerGoalHandle):
        with self.goal_lock_: # Avoid threads accessing each others goal_handles
            self.goal_handle_ = goal_handle
        
        # Get request from goal
        target = goal_handle.request.target_number
        period = goal_handle.request.period

        # Execute the action
        self.get_logger().info("Executing the goal")
        feedback = CountUntil.Feedback()
        result = CountUntil.Result()
        counter = 0
        for i in range(target):
            if goal_handle.is_cancel_requested:
                self.get_logger().info("Canceling the goal")
                goal_handle.canceled()
                result.reached_number = counter
                return result

            counter += 1
            self.get_logger().info(str(counter))
            feedback.current_number = counter
            goal_handle.publish_feedback(feedback)
            time.sleep(period)
        
        # Once done, set goal final state
        goal_handle.succeed()
        # goal_handle.abort()

        # and send the result
        result.reached_number = counter
        return result


def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServerNode()
    rclpy.spin(node, MultiThreadedExecutor())
    rclpy.shutdown()


if __name__ == "__main__":
    main()