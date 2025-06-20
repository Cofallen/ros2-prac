﻿// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from chap4_interface:srv/FaceDetector.idl
// generated code does not contain a copyright notice

#ifndef CHAP4_INTERFACE__SRV__DETAIL__FACE_DETECTOR__STRUCT_H_
#define CHAP4_INTERFACE__SRV__DETAIL__FACE_DETECTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/FaceDetector in the package chap4_interface.
typedef struct chap4_interface__srv__FaceDetector_Request
{
  /// 人脸图像
  sensor_msgs__msg__Image image;
} chap4_interface__srv__FaceDetector_Request;

// Struct for a sequence of chap4_interface__srv__FaceDetector_Request.
typedef struct chap4_interface__srv__FaceDetector_Request__Sequence
{
  chap4_interface__srv__FaceDetector_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} chap4_interface__srv__FaceDetector_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'top'
// Member 'right'
// Member 'bottom'
// Member 'left'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/FaceDetector in the package chap4_interface.
typedef struct chap4_interface__srv__FaceDetector_Response
{
  int16_t number;
  float use_time;
  rosidl_runtime_c__int32__Sequence top;
  rosidl_runtime_c__int32__Sequence right;
  rosidl_runtime_c__int32__Sequence bottom;
  rosidl_runtime_c__int32__Sequence left;
} chap4_interface__srv__FaceDetector_Response;

// Struct for a sequence of chap4_interface__srv__FaceDetector_Response.
typedef struct chap4_interface__srv__FaceDetector_Response__Sequence
{
  chap4_interface__srv__FaceDetector_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} chap4_interface__srv__FaceDetector_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CHAP4_INTERFACE__SRV__DETAIL__FACE_DETECTOR__STRUCT_H_
