from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()



    # Execute nodes
    ld.add_action(...) # turtlesim_window
    ld.add_action(...) # control_turtle
    ld.add_action(...) # spawn_turtles4
    return ld
