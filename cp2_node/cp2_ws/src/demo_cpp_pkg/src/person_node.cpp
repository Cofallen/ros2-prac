#include "rclcpp/rclcpp.hpp"

class PersonNode: public rclcpp::Node
{
    private:
        std::string name_;
        int age_;

    public:
        PersonNode(const std::string &node_name, const std::string &name, const int &age): Node(node_name)  // 调用父类构造函数 等同于 py 中 super().__init__(node_name)
        {
            this->name_ = name;
            this->age_ = age;
        };

        void eat(const std::string &food_name) {
            RCLCPP_INFO(this->get_logger(), "Person %s is %d years old, eatting %s", this->name_.c_str(), this->age_, food_name.c_str());
        };
};


int main(int argc, char ** argv) { 
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PersonNode> ("person_node", "Alice", 30);
    RCLCPP_INFO(node->get_logger(), "Person node has been created successfully!");
    
    node->eat("apple");
    try
    {
        rclcpp::spin(node);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}