#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String # Depends on the format of messages from subscribed topics


class SubscriberNode(Node): #TODO

    def __init__(self):
        super().__init__("[NAME OF NODE]") #TODO
        
        self.subscriber_ = self.create_subscription(String, "[NAME OF TOPIC]", self.callback_topic, 10)  #TODO # Topic to subscribe to
        
        self.get_logger().info("[NAME OF NODE] has been started.")

    def callback_topic(self, msg):
        self.get_logger().info(msg.data) # prints the received messages


def main(args=None):
    rclpy.init(args=args)
    node = SubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()