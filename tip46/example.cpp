#include <iostream>  
  
// 定义一个类模板  
template <typename T>  
class MyNumber {  
public:  
    // 构造函数  
    MyNumber(T value) : value_(value) {}  
  
    // 友元函数声明，用于转换  
    template <typename U>  
    friend MyNumber<U> convertToMyNumber(const U& value);  
  
    // 获取内部值  
    T getValue() const { return value_; }  
  
private:  
    T value_; // 私有成员  
};  
  
// 友元函数定义，用于类型转换  
template <typename U>  
MyNumber<U> convertToMyNumber(const U& value) {  
    // 这里可以添加必要的类型转换逻辑  
    return MyNumber<U>(value);  
}  
  
// 打印MyNumber对象值的函数  
template <typename T>  
void printValue(const MyNumber<T>& number) {  
    std::cout << "Value: " << number.getValue() << std::endl;  
}  
  
int main() {  
    // 使用convertToMyNumber进行隐式转换  
    printValue(convertToMyNumber(42));  // 输出：Value: 42  
    printValue(convertToMyNumber(3.14)); // 输出：Value: 3.14  
  
    // 由于convertToMyNumber是友元函数，它可以访问MyNumber的私有构造函数  
    // 这允许我们在不公开构造函数的情况下提供类型转换  
  
    return 0;  
}
