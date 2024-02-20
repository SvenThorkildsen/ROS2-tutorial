// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Turtle_pos_y
{
public:
  explicit Init_Turtle_pos_y(::my_robot_interfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::Turtle pos_y(::my_robot_interfaces::msg::Turtle::_pos_y_type arg)
  {
    msg_.pos_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::Turtle msg_;
};

class Init_Turtle_pos_x
{
public:
  explicit Init_Turtle_pos_x(::my_robot_interfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  Init_Turtle_pos_y pos_x(::my_robot_interfaces::msg::Turtle::_pos_x_type arg)
  {
    msg_.pos_x = std::move(arg);
    return Init_Turtle_pos_y(msg_);
  }

private:
  ::my_robot_interfaces::msg::Turtle msg_;
};

class Init_Turtle_name
{
public:
  Init_Turtle_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Turtle_pos_x name(::my_robot_interfaces::msg::Turtle::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Turtle_pos_x(msg_);
  }

private:
  ::my_robot_interfaces::msg::Turtle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::Turtle>()
{
  return my_robot_interfaces::msg::builder::Init_Turtle_name();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_
