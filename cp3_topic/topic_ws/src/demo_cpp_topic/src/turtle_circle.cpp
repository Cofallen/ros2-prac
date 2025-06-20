#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "chrono"

using namespace std::chrono_literals;

class TurtleCircleNode: public rclcpp::Node
{
private:
rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_; // 发布者的智能指针
public:
    explicit TurtleCircleNode(const std::string &node_name);  // ex.. 防止单参数进行隐式转换 TurtleCircleNode t = "xx";
    ~TurtleCircleNode();
    void timer_callback();
};

TurtleCircleNode::TurtleCircleNode(const std::string &node_name):Node(node_name)
{
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(1000ms, std::bind(&TurtleCircleNode::timer_callback, this));
}

TurtleCircleNode::~TurtleCircleNode()
{
}

void TurtleCircleNode::timer_callback() {
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x = 1.0;
    msg.angular.z = 0.5;
    publisher_->publish(msg);
}

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleCircleNode>("turtle_circle");
    try
    {
        rclcpp::spin(node);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    rclcpp::shutdown();

    return 0;
}