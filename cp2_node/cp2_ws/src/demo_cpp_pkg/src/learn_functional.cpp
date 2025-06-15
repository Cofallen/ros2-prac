#include "iostream"
#include "functional" // functional

// 自由函数 en: free function
void save_with_free_func(const std::string &filename) {
    std::cout << "free function saving to " << filename << std::endl;
}

// 成员函数 en: member function
class FileSave
{
private:
    
public:
    FileSave() = default;
    ~FileSave() = default;

    void save_with_member_func(const std::string &filename) {
        std::cout << "member function saving to " << filename << std::endl; 
    };
};

int main(int argc, char const *argv[])
{
    std::cout << argc << " arguments passed." << std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argument " << i << ": " << argv[i] << std::endl;
    }

    FileSave file_save;

    // lambda 函数 en: lambda function
    auto save_with_lambda_func = [](const std::string &filename) { std::cout << "lambda function saving to " << filename << std::endl; };

    // save_with_free_func("free_function.txt"); // 调用自由函数
    // file_save.save_with_member_func("member_function.txt"); // 调用成员函数
    // save_with_lambda_func("lambda_function.txt"); // 调用 lambda 函数 

    std::function<void(const std::string &)> save1 = save_with_free_func; // 使用 std::function 包装自由函数
    std::function<void(const std::string &)> save2 = save_with_lambda_func; // 使用 std::function 包装 lambda 函数
    // 成员函数，放入包装器
    std::function<void(const std::string &)> save3 = std::bind(&FileSave::save_with_member_func, &file_save, std::placeholders::_1); // 使用 std::bind 包装成员函数
    // std::bind 绑定成员函数时，需要指定对象的地址，std::placeholders::_1 表示占位符，表示传入的第一个参数

    // 调用包装后的函数 格式统一
    save1("free_function.txt"); // 调用自由函数
    save2("lambda_function.txt"); // 调用 lambda 函数
    save3("member_function.txt"); // 调用成员函数
    
    
    return 0;
}
