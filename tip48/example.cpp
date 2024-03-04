#include <iostream>  
  
// 递归终止条件  
template<int N>  
struct Factorial {  
    enum { value = N * Factorial<N - 1>::value };  
};  
  
// 递归基准情形  
template<>  
struct Factorial<0> {  
    enum { value = 1 };  
};  
  
int main() {  
    // 计算5的阶乘  
    std::cout << "5! = " << Factorial<5>::value << std::endl;  
  
    // 计算10的阶乘  
    std::cout << "10! = " << Factorial<10>::value << std::endl;  
  
    return 0;  
}
