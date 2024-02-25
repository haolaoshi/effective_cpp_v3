#include <iostream>  
#include <string>  
  
// 第一个基类  
class Base1 {  
public:  
    void printBase1() const {  
        std::cout << "Base1 function\n";  
    }  
};  
  
// 第二个基类  
class Base2 {  
public:  
    void printBase2() const {  
        std::cout << "Base2 function\n";  
    }  
};  
  
// 派生类，多重继承自Base1和Base2  
class Derived : public Base1, public Base2 {  
public:  
    void printDerived() const {  
        std::cout << "Derived function\n";  
    }  
};  
  
int main() {  
    Derived d;  
  
    // 调用Base1的成员函数  
    d.printBase1();  
  
    // 调用Base2的成员函数  
    d.printBase2();  
  
    // 调用Derived的成员函数  
    d.printDerived();  
  
    return 0;  
}