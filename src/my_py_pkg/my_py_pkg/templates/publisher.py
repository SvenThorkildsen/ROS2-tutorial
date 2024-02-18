#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64 # Depends on the format of the messages that are published

class PublisherNode(Node): # TODO

    def __init__(self):
        super().__init__("[NAME OF NODE]") # TODO

        self.publisher_ = self.create_publisher(Int64, "number", 10) # Topic: /number, queue size 10
        
        # Define rate of publication
        self.timer_ = self.create_timer(0.5, self.publish_function) 

        self.get_logger().info("[NAME OF NODE] has been started") # TODO

    def publish_function(self):
        # Format of message to be sent to publisher's topic
        msg = Int64()   

        # Content of message
        msg.data = 69   
        self.publisher_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = PublisherNode() # TODO
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()