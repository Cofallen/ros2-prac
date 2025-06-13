#include "iostream"

int main(int argc, char **argv)
{
    std::cout << "param count" << argc << std::endl;
    std::cout << "param0" << argv[0] << std::endl;

    if (argc > 1) {
        std::string arg1 = argv[1];
        if (arg1==std::string("--help")) {
            std::cout << "usage: ros2_cpp_node <arg1> <arg2>" << std::endl;
        }
    }
    
    return 0;

}