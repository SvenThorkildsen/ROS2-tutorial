# ROS2 Tutorial

This repository contains code and examples from the ROS2 course by Edouard Renard on Udemy, with some personal additions and modifications.

## Overview

This repository is organized around the ROS2 workspace named "ros2_ws" created at the beginning of the course. It includes various packages and code examples covering different aspects of ROS2 development.

## Prerequisites

Before using the code in this repository, make sure you have the following prerequisites installed:

- ROS2 Foxy Fitzroy or later version
- CMake
- Python 3
- Colcon build tool
- Any additional dependencies mentioned in the individual package README files

## Setup

To use the code in this repository, follow these steps:

1. Create a ROS2 workspace (e.g. "ros2_ws")
    ```
    mkdir ros2_ws
    ```
    
2. Navigate to the "ros2_ws" directory:

    ```
    cd ~/ros2_ws
    ```
   
3. Clone the repository to your workspace:

    ```
    git clone https://github.com/SvenThorkildsen/ROS2-tutorial.git
    ```

4. Build the ROS2 workspace using colcon:

    ```
    colcon build
    ```

5. Source the setup.bash file:

    ```
    source install/setup.bash
    ```

## Contents

The repository contains the following packages and examples:

- my_py_pkg:            Nodes written in Python.
- my_cpp_pkg:           Nodes written in C++.
- my_robot_interfaces:  Contains custom formats for messages and services

## Usage

To run the examples or use the packages in this repository, follow the instructions provided in the respective README files of each package.

## Contributing

Contributions to this repository are welcome! If you have any improvements, bug fixes, or new examples to add, feel free to submit a pull request.

## License

This code is provided under the MIT License.

## Acknowledgments

- Edouard Renard for the ROS2 course on Udemy.
- Contributors to the ROS2 project for their work on the ROS2 framework.

