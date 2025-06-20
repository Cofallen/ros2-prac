#include "QApplication"
#include "QLabel"
#include "QString"
#include <rclcpp/rclcpp.hpp>
#include "status_interfaces/msg/system_status.hpp"

using SystemStatus = status_interfaces::msg::SystemStatus;

class SystemDisplay: public rclcpp::Node
{
private:
    rclcpp::Subscription<SystemStatus>::SharedPtr subscriber_;
    std::shared_ptr<QLabel> label_;
    
public:
    SystemDisplay(const std::string &node_name);
    ~SystemDisplay();
    QString get_str_from_msg(const SystemStatus::SharedPtr msg);
};

SystemDisplay::SystemDisplay(const std::string &node_name):Node(node_name)
{
    // 创建没有文本的标签
    label_ = std::make_shared<QLabel>();
    subscriber_ = create_subscription<SystemStatus>("sys_status", 10, [&](const SystemStatus::SharedPtr msg) -> void{
        label_->setText(get_str_from_msg(msg));
    });
    label_->setText(get_str_from_msg(std::make_shared<SystemStatus>()));  // 没有数据时显示空
    label_->show();
}

SystemDisplay::~SystemDisplay()
{
}

QString SystemDisplay::get_str_from_msg(const SystemStatus::SharedPtr msg){
    std::stringstream show_str;
    show_str << "============系统状态可视化工具============\n"
    <<           "数据时间： \t" << msg->stamp.sec << "\ts\n" 
    <<           "主机名字： \t" << msg->host_name << "\t\n" 
    <<           "CPU使用率: \t" << msg->cpu_percent << "\t%\n" 
    <<           "内存使用率： \t" << msg->memory_percent << "\t%\n" 
    <<           "内存总大小： \t" << msg->memory_total << "\tMB\n" 
    <<           "剩余有效内存： \t" << msg->memory_available << "\tMB\n" 
    <<           "网络发送量： \t" << msg->net_sent << "\tMB\n" 
    <<           "网络接收量： \t" << msg->net_recv << "\tMB\n"
    <<          "=======================================\n";
    return QString::fromStdString(show_str.str());
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    QApplication app(argc, argv);
    auto node = std::make_shared<SystemDisplay>("qt_display_node");

    std::thread spin_thread([&]()->void{
        rclcpp::spin(node);
    });
    spin_thread.detach();

    try
    {
        app.exec();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
