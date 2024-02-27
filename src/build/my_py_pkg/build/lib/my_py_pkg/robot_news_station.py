#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String


class RobotNewsStationNode(Node):

    def __init__(self):
        super().__init__("robot_news_station") # Same name for file and node

        self.declare_parameter("robot_name", "robot name")
        self.robot_name_ = self.get_parameter("robot_name")

        self.publisher_ = self.create_publisher(String, "robot_news", 10) # Topic robot_news, queue size 10
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot News Station has been started")


    def publish_news(self):
        msg = String()
        msg.data = "Hi, this is " + str(self.robot_name_) +  " from the Robot News Station" # Message to be sent to publisher's topic
        self.publisher_.publish(msg)



def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()