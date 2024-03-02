#include <iostream>  
  
// 模板基类  
template <typename T>  
class Base {  
public:  
    void foo() {  
        std::cout << "Base::foo()" << std::endl;  
    }  
};  
  
// 特化版本，没有foo()函数  
template <>  
class Base<int> {  
public:  
    void bar() {  
        std::cout << "Base<int>::bar()" << std::endl;  
    }  
};  
  
// 派生类模板  
template <typename T>  
class Derived : public Base<T> {  
public:  
    void callFoo() {  
        // 直接调用会导致编译错误，因为Base<int>没有foo()  
        //this->foo(); // 错误  error: ‘class Derived<int>’ has no member named ‘foo’ 
  
        // 使用基类资格修饰符来明确指定我们想要调用的是模板基类中的foo()  
        //Base<T>::foo();  //‘foo’ is not a member of ‘Base<int>’
    }  
};  
  
int main() {  
    Derived<int> d;  
    d.callFoo();  // 输出：Base::foo()  
  
    return 0;  
}
