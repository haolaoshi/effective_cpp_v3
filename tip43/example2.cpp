#include <iostream>  
  
// 模板基类  
template <typename T>  
class Base {  
public:  
    void foo() {  
        std::cout << "Base::foo()" << std::endl;  
    }  
};  
  
// 特化版本，没有提供foo()函数  
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
    // 使用this->指针显式调用模板基类中的foo()  
    void callFooViaThis() {  
        this->foo();  
    }  
  
    // 使用基类模板的资格修饰符来调用foo()  
    void callFooViaQualifier() {  
        Base<T>::foo();  //error: ‘foo’ is not a member of ‘Base<int>’
    }  
};  
  
int main() {  
    // 对于非特化类型，两种方法都可以调用Base::foo()  
    Derived<double> d1;  
    d1.callFooViaThis();  // 输出：Base::foo()  
    d1.callFooViaQualifier();  // 输出：Base::foo()  
  
    // 对于特化类型int，只有使用资格修饰符的方法可以编译通过  
    Derived<int> d2;  
    // d2.callFooViaThis(); // 这将导致编译错误，因为Base<int>没有foo()  
    d2.callFooViaQualifier();  // 输出：Base::foo()，这里调用的是模板版本的Base<T>::foo()  
  
    return 0;  
}
