#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

# Import necessary communication packages
# from example_interfaces.msg import String
from my_robot_interfaces.msg import HardwareStatus

class HardwareStatusPublisherNode(Node): 

    def __init__(self):
        super().__init__("hardware_status_publisher") 

        self.hw_status_publisher_ = self.create_publisher(HardwareStatus, "hardware_status", 10) # Topic: /number, queue size 10
        
        # Define rate of publication
        self.timer_ = self.create_timer(1.0, self.publish_hardware_status) 

        self.get_logger().info("Hardware Status node has been started")

    def publish_hardware_status(self):
        # Format of message to be sent to publisher's topic
        msg = HardwareStatus()   
        
        # Content of message
        msg.temperature = 69
        msg.are_motors_ready = True
        msg.debug_message = ("Temperature: " + str(msg.temperature) + ". Motor status: " + str(msg.are_motors_ready))  

        # Publish message on topic
        self.hw_status_publisher_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()