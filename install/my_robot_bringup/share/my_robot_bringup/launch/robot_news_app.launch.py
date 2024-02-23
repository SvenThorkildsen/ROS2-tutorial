from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()


    robot_names = ["giskard", "bb8", "daneel", "jander", "c3po"]

    robot_news_station_nodes = []

    for name in robot_names:
        robot_news_station_nodes.append(Node(
            package="my_cpp_pkg",
            executable="robot_news_station",
            name="robot_news_station_" + name.lower(),
            parameters=[{"robot_name": name}]
        ))


    # robot_news_station_giskard_node = Node(
    #     package="my_cpp_pkg",
    #     executable="robot_news_station",
    #     name="robot_news_station_giskard",
    #     parameters=[
    #         {"robot_name":"giskard"}
    #     ]
    # )

    # robot_news_station_bb8_node = Node(
    #     package="my_cpp_pkg",
    #     executable="robot_news_station",
    #     name="robot_news_station_bb8",
    #     parameters=[
    #         {"robot_name":"bb8"}
    #     ]
    # )

    # robot_news_station_daneel_node = Node(
    #     package="my_cpp_pkg",
    #     executable="robot_news_station",
    #     name="robot_news_station_daneel",
    #     parameters=[
    #         {"robot_name":"daneel"}
    #     ]
    # )

    # robot_news_station_jander_node = Node(
    #     package="my_cpp_pkg",
    #     executable="robot_news_station",
    #     name="robot_news_station_jander",
    #     parameters=[
    #         {"robot_name":"jander"}
    #     ]
    # )

    # robot_news_station_c3po_node = Node(
    #     package="my_cpp_pkg",
    #     executable="robot_news_station",
    #     name="robot_news_station_c3po",
    #     parameters=[
    #         {"robot_name":"c3po"}
    #     ]
    # )

    smartphone_node = Node(
        package="my_cpp_pkg",
        executable="smartphone"
    )


    for node in robot_news_station_nodes:
        ld.add_action(node)
    # ld.add_action(robot_news_station_giskard_node)
    # ld.add_action(robot_news_station_bb8_node)
    # ld.add_action(robot_news_station_daneel_node)
    # ld.add_action(robot_news_station_jander_node)
    # ld.add_action(robot_news_station_c3po_node)
    ld.add_action(smartphone_node)
    return ld

