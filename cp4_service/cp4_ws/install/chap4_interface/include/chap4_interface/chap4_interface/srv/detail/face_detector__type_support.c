// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from chap4_interface:srv/FaceDetector.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "chap4_interface/srv/detail/face_detector__rosidl_typesupport_introspection_c.h"
#include "chap4_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "chap4_interface/srv/detail/face_detector__functions.h"
#include "chap4_interface/srv/detail/face_detector__struct.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  chap4_interface__srv__FaceDetector_Request__init(message_memory);
}

void chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_fini_function(void * message_memory)
{
  chap4_interface__srv__FaceDetector_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_member_array[1] = {
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Request, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_members = {
  "chap4_interface__srv",  // message namespace
  "FaceDetector_Request",  // message name
  1,  // number of fields
  sizeof(chap4_interface__srv__FaceDetector_Request),
  chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_member_array,  // message members
  chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_type_support_handle = {
  0,
  &chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_chap4_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector_Request)() {
  chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_type_support_handle.typesupport_identifier) {
    chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &chap4_interface__srv__FaceDetector_Request__rosidl_typesupport_introspection_c__FaceDetector_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "chap4_interface/srv/detail/face_detector__rosidl_typesupport_introspection_c.h"
// already included above
// #include "chap4_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "chap4_interface/srv/detail/face_detector__functions.h"
// already included above
// #include "chap4_interface/srv/detail/face_detector__struct.h"


// Include directives for member types
// Member `top`
// Member `right`
// Member `bottom`
// Member `left`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  chap4_interface__srv__FaceDetector_Response__init(message_memory);
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_fini_function(void * message_memory)
{
  chap4_interface__srv__FaceDetector_Response__fini(message_memory);
}

size_t chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__top(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__top(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__top(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__top(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__top(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__top(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__top(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__top(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__right(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__right(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__right(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__right(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__right(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__right(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__right(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__right(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__bottom(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__bottom(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__bottom(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__bottom(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__bottom(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__bottom(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__bottom(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__bottom(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__left(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__left(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__left(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__left(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__left(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__left(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__left(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__left(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_member_array[6] = {
  {
    "number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Response, number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "use_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Response, use_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "top",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Response, top),  // bytes offset in struct
    NULL,  // default value
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__top,  // size() function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__top,  // get_const(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__top,  // get(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__top,  // fetch(index, &value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__top,  // assign(index, value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__top  // resize(index) function pointer
  },
  {
    "right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Response, right),  // bytes offset in struct
    NULL,  // default value
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__right,  // size() function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__right,  // get_const(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__right,  // get(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__right,  // fetch(index, &value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__right,  // assign(index, value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__right  // resize(index) function pointer
  },
  {
    "bottom",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Response, bottom),  // bytes offset in struct
    NULL,  // default value
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__bottom,  // size() function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__bottom,  // get_const(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__bottom,  // get(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__bottom,  // fetch(index, &value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__bottom,  // assign(index, value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__bottom  // resize(index) function pointer
  },
  {
    "left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(chap4_interface__srv__FaceDetector_Response, left),  // bytes offset in struct
    NULL,  // default value
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__size_function__FaceDetector_Response__left,  // size() function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_const_function__FaceDetector_Response__left,  // get_const(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__get_function__FaceDetector_Response__left,  // get(index) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__fetch_function__FaceDetector_Response__left,  // fetch(index, &value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__assign_function__FaceDetector_Response__left,  // assign(index, value) function pointer
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__resize_function__FaceDetector_Response__left  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_members = {
  "chap4_interface__srv",  // message namespace
  "FaceDetector_Response",  // message name
  6,  // number of fields
  sizeof(chap4_interface__srv__FaceDetector_Response),
  chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_member_array,  // message members
  chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_type_support_handle = {
  0,
  &chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_chap4_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector_Response)() {
  if (!chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_type_support_handle.typesupport_identifier) {
    chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &chap4_interface__srv__FaceDetector_Response__rosidl_typesupport_introspection_c__FaceDetector_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "chap4_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "chap4_interface/srv/detail/face_detector__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_members = {
  "chap4_interface__srv",  // service namespace
  "FaceDetector",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_Request_message_type_support_handle,
  NULL  // response message
  // chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_Response_message_type_support_handle
};

static rosidl_service_type_support_t chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_type_support_handle = {
  0,
  &chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_chap4_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector)() {
  if (!chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_type_support_handle.typesupport_identifier) {
    chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, chap4_interface, srv, FaceDetector_Response)()->data;
  }

  return &chap4_interface__srv__detail__face_detector__rosidl_typesupport_introspection_c__FaceDetector_service_type_support_handle;
}
