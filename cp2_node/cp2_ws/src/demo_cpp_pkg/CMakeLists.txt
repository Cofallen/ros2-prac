cmake_minimum_required(VERSION 3.8)
project(demo_cpp_pkg)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# find_package(Threads REQUIRED)
# Find the required ROS 2 packages
find_package(rclcpp REQUIRED)
# uncomment the following section in order to fill in
include_directories(include)

add_executable(cpp_node src/cpp_node.cpp)
add_executable(person_node src/person_node.cpp)
add_executable(learn_auto src/learn_auto.cpp)
add_executable(learn_shared_ptr src/learn_shared_ptr.cpp)
add_executable(learn_lambda src/learn_lambda.cpp)
add_executable(learn_functional src/learn_functional.cpp)
add_executable(learn_thread src/learn_thread.cpp)

# 包含连接
# target_include_directories(cpp_node 
#   PUBLIC ${rclcpp_INCLUDE_DIRS} )
# target_link_libraries(cpp_node 
#   ${rclcpp_LIBRARIES} )
ament_target_dependencies(cpp_node rclcpp) # 等效上面两个
ament_target_dependencies(person_node rclcpp) 
ament_target_dependencies(learn_auto rclcpp) 
ament_target_dependencies(learn_shared_ptr rclcpp) 
ament_target_dependencies(learn_lambda rclcpp) 

# target_link_libraries(learn_thread PRIVATE Threads::Threads)
# target_link_libraries(learn_thread PRIVATE ${CMAKE_DL_LIBS})

install(TARGETS  person_node learn_auto  learn_shared_ptr learn_lambda learn_functional learn_thread 
 DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
