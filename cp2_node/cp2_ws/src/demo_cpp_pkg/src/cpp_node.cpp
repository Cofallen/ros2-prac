#include "iostream"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // 可修改名称
    auto node = std::make_shared<rclcpp::Node>("cpp_node");
    RCLCPP_INFO(node->get_logger(), "Hello, ROS 2 from C++ node!");
    // 运行
    rclcpp::spin(node);
    // 清理
    rclcpp::shutdown();
    std::cout << "Node has been shut down." << std::endl;
    return 0;

}