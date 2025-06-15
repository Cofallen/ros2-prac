#include "iostream"
#include "algorithm" // lambda

int main(int argc, char const *argv[])
{
    std::cout << argc << " arguments passed." << std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argument " << i << ": " << argv[i] << std::endl;
    }

    auto add = [](int a, int b) -> int {return (a + b);};
    int sum = add(3, 4);
    auto print_sum = [sum]() -> void {
        std::cout << "the sum is " << sum
 << std::endl; // if [&], capture all variables by reference.
    };
    
    print_sum();
    return 0;
}
