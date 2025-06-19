#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include "chrono"

// #define DEBUG_PID    1
#define DEBUG_CLASS  0

#define NOW  0
#define LAST 1

class PIDControler
{
private:
    double kp_;
    double ki_;
    double kd_;

    double err_[2];
    double err_sum_;
    double max_limit_;
public:
    PIDControler(): kp_{1.0}, ki_{0.0}, kd_{0.0}, err_{0.0, 0.0}, err_sum_{0.0}, max_limit_{0.0}{};
    ~PIDControler();
    double compute(double target, double realval);
    void reset();
    void setParameters(double kp, double ki, double kd, double max_limit);
};


PIDControler::~PIDControler()
{
}

double PIDControler::compute(double target, double realval) {

    double output = 0.0;

    err_[NOW] = target - realval;

    err_sum_ += err_[NOW];

    double derivative = (err_[NOW] - err_[LAST]);
    output = kp_ * err_[NOW] + ki_ * err_sum_ + kd_ * derivative;

    // 输出限幅
    if (output > max_limit_) {
        output = max_limit_;
    } else if (output < -max_limit_) {
        output = -max_limit_;
    }
    err_[LAST] = err_[NOW];

    return output;
}

void PIDControler::reset() {
    err_[NOW] = 0.0;
    err_[LAST] = 0.0;
    err_sum_ = 0.0;
}

void PIDControler::setParameters(double kp, double ki, double kd, double max_limit) {
    kp_ = kp;
    ki_ = ki;
    kd_ = kd;
    max_limit_ = max_limit;
}

class TurtleControlNode: public rclcpp::Node, PIDControler
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr  subscriber_; // 订阅者的智能共享指针
    double target_x_{1.0};
    double target_y_{1.0};
    double k_{1.0};  //  比例系数
    double max_speed_{3.0};  //  限幅

    PIDControler linear_pid_;
    PIDControler angular_pid_;

public:
    explicit TurtleControlNode(const std::string &node_name);
    ~TurtleControlNode();
    void subscriber_callback(const turtlesim::msg::Pose::SharedPtr pose);  // 受到数据回调
};

TurtleControlNode::TurtleControlNode(const std::string &node_name):Node(node_name)
{
    linear_pid_.setParameters(0.8, 0.01, 0.1, 2.0);
    angular_pid_.setParameters(1.5, 0.01, 0.1, 3.0);
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    subscriber_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&TurtleControlNode::subscriber_callback, this, std::placeholders::_1));
    
}

TurtleControlNode::~TurtleControlNode()
{
}




/**
 * @param pose 受到数据的共享指针
 */
void TurtleControlNode::subscriber_callback(const turtlesim::msg::Pose::SharedPtr pose) {
    // 1. 获取当前位置
    auto current_x = pose->x;
    auto current_y = pose->y; 
    RCLCPP_INFO(get_logger(), "当前: x=%f, y=%f", current_x, current_y);

    // 2. 计算当前海龟位置和目标位置之间的距离差和角度
    auto distance = std::sqrt(
        (target_x_ - current_x) * (target_x_ - current_x) + (target_y_ - current_y) * (target_y_ - current_y));
    auto angle = std::atan2((target_y_ - current_y), (target_x_ - current_x));
    auto angle_err = angle - pose->theta;
    // RCLCPP_INFO(get_logger(), "abgle %f", angle_err);
    // 3. 控制策略
    auto msg = geometry_msgs::msg::Twist();

    #ifdef DEBUG_PID
    msg.angular.z = angular_pid_.compute(angle, pose->theta);
    if (fabs(angle_err) <= 0.2)
    {
        msg.linear.x = linear_pid_.compute(0.0, -distance);
    }
    
    #else  DEBUG_CLASS
    if (distance > 0.1)
    {
        if (fabs(angle_err) > 0.2)
        {
            msg.angular.z = fabs(angle_err);
        } else {
            msg.linear.x = distance * k_;
        }
        
    }

    // 4. 限制线速度最大值
    if (msg.linear.x > max_speed_)
    {
        msg.linear.x = max_speed_;
    }
    #endif

    publisher_->publish(msg);
}
int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TurtleControlNode>("turtle_control");

    try
    {
        rclcpp::spin(node);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
