#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node): # TODO

    def __init__(self):
        super().__init__("[NODE]") # TODO
        self.get_logger().info("[NAME OF NODE] has been started") # TODO


def main(args=None):
    rclpy.init(args=args)
    node = MyNode() # TODO
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()