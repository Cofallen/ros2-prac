cmake_minimum_required(VERSION 3.10)
project(ros2_node)
add_executable(ros2_node ros2_cpp_node.cpp)

# Find the required ROS 2 packages
find_package(rclcpp REQUIRED)
# message(STATUS ${rclcpp_INCLUDE_DIRS})
# message(STATUS ${rclcpp_LIBRARIES}) # .SO 动态连接库

#；包含连接
target_include_directories(ros2_node 
  PUBLIC ${rclcpp_INCLUDE_DIRS} )
target_link_libraries(ros2_node 
  ${rclcpp_LIBRARIES} )