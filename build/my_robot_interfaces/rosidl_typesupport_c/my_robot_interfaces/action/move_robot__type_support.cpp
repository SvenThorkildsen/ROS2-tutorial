// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from my_robot_interfaces:action/MoveRobot.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "my_robot_interfaces/action/detail/move_robot__struct.h"
#include "my_robot_interfaces/action/detail/move_robot__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_Goal_type_support_ids_t;

static const _MoveRobot_Goal_type_support_ids_t _MoveRobot_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_Goal_type_support_symbol_names_t _MoveRobot_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_Goal)),
  }
};

typedef struct _MoveRobot_Goal_type_support_data_t
{
  void * data[2];
} _MoveRobot_Goal_type_support_data_t;

static _MoveRobot_Goal_type_support_data_t _MoveRobot_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_Goal_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_Goal)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_Result_type_support_ids_t;

static const _MoveRobot_Result_type_support_ids_t _MoveRobot_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_Result_type_support_symbol_names_t _MoveRobot_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_Result)),
  }
};

typedef struct _MoveRobot_Result_type_support_data_t
{
  void * data[2];
} _MoveRobot_Result_type_support_data_t;

static _MoveRobot_Result_type_support_data_t _MoveRobot_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_Result_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_Result)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_Feedback_type_support_ids_t;

static const _MoveRobot_Feedback_type_support_ids_t _MoveRobot_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_Feedback_type_support_symbol_names_t _MoveRobot_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_Feedback)),
  }
};

typedef struct _MoveRobot_Feedback_type_support_data_t
{
  void * data[2];
} _MoveRobot_Feedback_type_support_data_t;

static _MoveRobot_Feedback_type_support_data_t _MoveRobot_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_Feedback_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_Feedback)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_SendGoal_Request_type_support_ids_t;

static const _MoveRobot_SendGoal_Request_type_support_ids_t _MoveRobot_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_SendGoal_Request_type_support_symbol_names_t _MoveRobot_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_SendGoal_Request)),
  }
};

typedef struct _MoveRobot_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MoveRobot_SendGoal_Request_type_support_data_t;

static _MoveRobot_SendGoal_Request_type_support_data_t _MoveRobot_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_SendGoal_Request_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_SendGoal_Request)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_SendGoal_Response_type_support_ids_t;

static const _MoveRobot_SendGoal_Response_type_support_ids_t _MoveRobot_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_SendGoal_Response_type_support_symbol_names_t _MoveRobot_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_SendGoal_Response)),
  }
};

typedef struct _MoveRobot_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MoveRobot_SendGoal_Response_type_support_data_t;

static _MoveRobot_SendGoal_Response_type_support_data_t _MoveRobot_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_SendGoal_Response_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_SendGoal_Response)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_SendGoal_type_support_ids_t;

static const _MoveRobot_SendGoal_type_support_ids_t _MoveRobot_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_SendGoal_type_support_symbol_names_t _MoveRobot_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_SendGoal)),
  }
};

typedef struct _MoveRobot_SendGoal_type_support_data_t
{
  void * data[2];
} _MoveRobot_SendGoal_type_support_data_t;

static _MoveRobot_SendGoal_type_support_data_t _MoveRobot_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_SendGoal_service_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveRobot_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_SendGoal)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_GetResult_Request_type_support_ids_t;

static const _MoveRobot_GetResult_Request_type_support_ids_t _MoveRobot_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_GetResult_Request_type_support_symbol_names_t _MoveRobot_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_GetResult_Request)),
  }
};

typedef struct _MoveRobot_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MoveRobot_GetResult_Request_type_support_data_t;

static _MoveRobot_GetResult_Request_type_support_data_t _MoveRobot_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_GetResult_Request_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_GetResult_Request)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_GetResult_Response_type_support_ids_t;

static const _MoveRobot_GetResult_Response_type_support_ids_t _MoveRobot_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_GetResult_Response_type_support_symbol_names_t _MoveRobot_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_GetResult_Response)),
  }
};

typedef struct _MoveRobot_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MoveRobot_GetResult_Response_type_support_data_t;

static _MoveRobot_GetResult_Response_type_support_data_t _MoveRobot_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_GetResult_Response_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_GetResult_Response)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_GetResult_type_support_ids_t;

static const _MoveRobot_GetResult_type_support_ids_t _MoveRobot_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_GetResult_type_support_symbol_names_t _MoveRobot_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_GetResult)),
  }
};

typedef struct _MoveRobot_GetResult_type_support_data_t
{
  void * data[2];
} _MoveRobot_GetResult_type_support_data_t;

static _MoveRobot_GetResult_type_support_data_t _MoveRobot_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_GetResult_service_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveRobot_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_GetResult)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__struct.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace my_robot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveRobot_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveRobot_FeedbackMessage_type_support_ids_t;

static const _MoveRobot_FeedbackMessage_type_support_ids_t _MoveRobot_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveRobot_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveRobot_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveRobot_FeedbackMessage_type_support_symbol_names_t _MoveRobot_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, action, MoveRobot_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, action, MoveRobot_FeedbackMessage)),
  }
};

typedef struct _MoveRobot_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MoveRobot_FeedbackMessage_type_support_data_t;

static _MoveRobot_FeedbackMessage_type_support_data_t _MoveRobot_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveRobot_FeedbackMessage_message_typesupport_map = {
  2,
  "my_robot_interfaces",
  &_MoveRobot_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MoveRobot_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MoveRobot_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveRobot_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveRobot_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace my_robot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_FeedbackMessage)() {
  return &::my_robot_interfaces::action::rosidl_typesupport_c::MoveRobot_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "my_robot_interfaces/action/move_robot.h"
// already included above
// #include "my_robot_interfaces/action/detail/move_robot__type_support.h"

static rosidl_action_type_support_t _my_robot_interfaces__action__MoveRobot__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot)()
{
  // Thread-safe by always writing the same values to the static struct
  _my_robot_interfaces__action__MoveRobot__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_SendGoal)();
  _my_robot_interfaces__action__MoveRobot__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_GetResult)();
  _my_robot_interfaces__action__MoveRobot__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _my_robot_interfaces__action__MoveRobot__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, my_robot_interfaces, action, MoveRobot_FeedbackMessage)();
  _my_robot_interfaces__action__MoveRobot__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_my_robot_interfaces__action__MoveRobot__typesupport_c;
}

#ifdef __cplusplus
}
#endif
