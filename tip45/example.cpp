#include <iostream>  
#include <string>  
  
// 定义一个类模板  
template <typename T>  
class MyClass {  
public:  
    // 成员函数模板，可以接受与T兼容的所有类型  
    template <typename U>  
    void print(const U& value) {  
        std::cout << "Value: " << value << std::endl;  
    }  
  
    // 一个普通的成员函数，仅接受T类型  
    void foo() {  
        std::cout << "This is a regular member function." << std::endl;  
    }  
};  
  
int main() {  
    // 创建MyClass<int>的实例  
    MyClass<int> myInt;  
  
    // 使用成员函数模板print，传入int类型  
    myInt.print(10);  
  
    // 使用成员函数模板print，传入double类型  
    myInt.print(3.14);  
  
    // 使用成员函数模板print，传入std::string类型  
    myInt.print("Hello, World!");  
  
    // 使用普通成员函数foo  
    myInt.foo();  
  
    // 创建MyClass<std::string>的实例  
    MyClass<std::string> myString;  
  
    // 使用成员函数模板print，传入std::string类型  
    myString.print("Another string");  
  
    // 使用成员函数模板print，传入const char*类型  
    myString.print("Pointer to const char");  
  
    // 使用普通成员函数foo  
    myString.foo();  
  
    return 0;  
}
