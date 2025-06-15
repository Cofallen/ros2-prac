#include "iostream"
#include "memory"

int main() {
    auto p1 = std::make_shared<std::string>("this is a string.");    // std::make_shared<type/class>(param); return type;  in this case std::shared_ptr<std::string> => auto 
    std::cout << "p1 in count" << p1.use_count() << ", memory address:" << p1.get() << std::endl; // 1 

    auto p2 = p1;  // p2 is a shared pointer, which shares the ownership of the object with p1
    std::cout << "p1 in count" << p1.use_count() << ", memory address:" << p1.get() << std::endl; //2
    std::cout << "p2 in count" << p2.use_count() << ", memory address:" << p2.get() << std::endl; //2 (in the same memory address as p1)
    
    p1.reset();  // reset p1, which will free "this is a string." if no other shared pointers are pointing to it
    std::cout << "p1 in count" << p1.use_count() << ", memory address:" << p1.get() << std::endl; // 0, p1 is reset
    std::cout << "p2 in count" << p2.use_count() << ", memory address:" << p2.get() << std::endl; // 1, p2 still points to "this is a string."

    std::cout << "p2 content: " << p2->c_str() << std::endl; // dereference p2 to get the string content

    return 0;
}