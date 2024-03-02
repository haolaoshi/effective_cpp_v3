//SFINAE (Substitution Failure Is Not An Error) 

#include <iostream>
#include <type_traits>

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

// 辅助模板，用于SFINAE
template <typename T, typename = void>
struct HasFoo : std::false_type {};

// 特化版本，当T有foo()函数时
template <typename T>
struct HasFoo<T, std::void_t<decltype(std::declval<T>().foo())>> : std::true_type {};

// 派生类模板
template <typename T>
class Derived : public Base<T> {
public:
    // 使用SFINAE来根据是否有foo()选择不同的实现
    typename std::enable_if<HasFoo<Base<T>>::value, void>::type
    callFoo() {
        Base<T>::foo();
    }

    typename std::enable_if<!HasFoo<Base<T>>::value, void>::type
    callFoo() {
        // 对于没有foo()的特化版本，可以选择不做什么，或者调用其他函数
    }
};

int main() {
    Derived<double> d1;
    d1.callFoo();  // 输出：Base::foo()

    Derived<int> d2;
    d2.callFoo();  // 对于int类型，调用没有foo()的Base特化版本，不会输出任何内容

    return 0;
}
