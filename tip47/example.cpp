#include <iostream>  
#include <type_traits>  
  
// 定义一个特性类模板，用于判断类型T是否是std::string  
template<typename T>  
struct IsString {  
    static const bool value = false;  
};  
  
// 为std::string特化该模板  
template<>  
struct IsString<std::string> {  
    static const bool value = true;  
};  
  
// 示例函数，使用IsString特性类来判断类型  
template<typename T>  
void printTypeInfo(const T& value) {  
    if (IsString<T>::value) {  
        std::cout << "The type is std::string." << std::endl;  
    } else {  
        std::cout << "The type is not std::string." << std::endl;  
    }  
}  
  
int main() {  
    std::string str = "Hello, World!";  
    int num = 42;  
  
    printTypeInfo(str);  // 输出 "The type is std::string."  
    printTypeInfo(num);  // 输出 "The type is not std::string."  
  
    return 0;  
}
