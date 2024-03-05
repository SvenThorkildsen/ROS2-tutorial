#!/usr/bin/env python3
import rclpy
# from rclpy.node import Node
from rclpy.lifecycle import LifecycleNode
from rclpy.lifecycle.node import LifecycleState, TransitionCallbackReturn

from example_interfaces.msg import Int64



class NumberPublisherNode(LifecycleNode):
    def __init__(self):
        super().__init__("number_publisher")
        self.get_logger().info("IN constructor")
        self.number_ = 1
        self.publish_frequency_ = 1.0
        self.number_publisher_ = None
        self.number_timer_ = None


    # Create ROS2 communications, connect to HW
    def on_configure(self, previous_state: LifecycleState) -> TransitionCallbackReturn:
        self.get_logger().info("IN on_configure")
        self.number_publisher_ = self.create_lifecycle_publisher(Int64, "number", 10) # lifecycle publishers will not be able to publish unless the node is in the 'active' state
        self.number_timer_ = self.create_timer(
            1.0 / self.publish_frequency_, self.publish_number)
        self.number_timer_.cancel()
        # raise Exception()
        return TransitionCallbackReturn.SUCCESS
    
    # Destroy ROS2 communications, disconnect form HW (Revert the actions of on_cleanup)
    def on_cleanup(self, previous_state: LifecycleState) -> TransitionCallbackReturn:
        self.get_logger().info("IN on_cleanup")
        self.destroy_lifecycle_publisher(self.number_publisher_)
        self.destroy_timer(self.number_timer_)
        return TransitionCallbackReturn.SUCCESS
    

    # Activate/Enable HW
    def on_activate(self, previous_state: LifecycleState) -> TransitionCallbackReturn:
        self.get_logger().info("IN on_activate")
        self.number_timer_.reset()
        return super().on_activate(previous_state)
    

    # Deactivate/Disable HW (Revert the actions of on_activate)
    def on_deactivate(self, previous_state: LifecycleState) -> TransitionCallbackReturn:
        self.get_logger().info("IN on_deactivate")
        self.number_timer_.cancel()
        return super().on_deactivate(previous_state)
    

    # Finalize/Terminate the node (Same functionality as on_cleanup, but can be accessed from all states)
    def on_shutdown(self, previous_state: LifecycleState) -> TransitionCallbackReturn:
        self.get_logger().info("IN on_shutdown")
        self.destroy_lifecycle_publisher(self.number_publisher_)
        self.destroy_timer(self.number_timer_)
        return TransitionCallbackReturn.SUCCESS
    

    # Process errors, deactivate + cleanup
        # on_error is when an error flag is raised, but the function does not know what caused the error
    def on_error(self, previous_state: LifecycleState) -> TransitionCallbackReturn:
        self.get_logger().info("IN on_error")
        self.destroy_lifecycle_publisher(self.number_publisher_)
        self.destroy_timer(self.number_timer_)
        # do some checks, if ok, then return SUCCESS (->unconfigured), if not FAILURE(->finalized)
        return TransitionCallbackReturn.FAILURE
    

    def publish_number(self):
        msg = Int64()
        msg.data = self.number_
        self.number_publisher_.publish(msg)
        self.number_ += 1


def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()
