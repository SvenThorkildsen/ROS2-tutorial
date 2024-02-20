cmake_minimum_required(VERSION 3.8)
project(turtlesim_catch_them_all)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(my_robot_interfaces REQUIRED)



add_executable(turtle_controller src/turtle_controller_node.cpp)
ament_target_dependencies(turtle_controller my_robot_interfaces rclcpp turtlesim)

add_executable(turtle_spawner src/turtle_spawner_node.cpp)
ament_target_dependencies(turtle_spawner my_robot_interfaces rclcpp turtlesim)


install(TARGETS
  turtle_controller
  turtle_spawner
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
