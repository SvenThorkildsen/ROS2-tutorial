#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64

class NumberPublisherNode(Node): # TODO

    def __init__(self):
        super().__init__("number_publisher") # TODO
        self.number_ = 2

        self.number_publisher_ = self.create_publisher(Int64, "number", 10) # Topic: /number, queue size 10
        self.timer_ = self.create_timer(0.5, self.publish_number)

        self.get_logger().info("Number Publisher has been started") # TODO

    def publish_number(self):
        msg = Int64()
        msg.data = self.number_ # Message to be sent to publisher's topic
        self.number_publisher_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode() # TODO
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()