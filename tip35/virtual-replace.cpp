#include <iostream>  
  
// 抽象基类（接口）定义策略  
class Strategy {  
public:  
    virtual ~Strategy() = default; // 虚析构函数，保证派生类对象可以正确析构  
    virtual void execute() const = 0; // 纯虚函数，定义策略的行为  
};  
  
// 具体策略A  
class StrategyA : public Strategy {  
public:  
    void execute() const override {  
        std::cout << "Executing strategy A" << std::endl;  
    }  
};  
  
// 具体策略B  
class StrategyB : public Strategy {  
public:  
    void execute() const override {  
        std::cout << "Executing strategy B" << std::endl;  
    }  
};  
  
// 上下文类，使用Strategy指针作为成员变量  
class Context {  
private:  
    Strategy* strategy;  
  
public:  
    // 构造函数，接受一个Strategy指针  
    Context(Strategy* strategy) : strategy(strategy) {}  
  
    // 执行策略  
    void setStrategy(Strategy* newStrategy) {  
        strategy = newStrategy;  
    }  
  
    void executeStrategy() {  
        if (strategy) {  
            strategy->execute();  
        } else {  
            std::cout << "No strategy set!" << std::endl;  
        }  
    }  
};  
  
int main() {  
    // 创建策略对象  
    StrategyA strategyA;  
    StrategyB strategyB;  
  
    // 创建上下文对象，并设置初始策略  
    Context context(&strategyA);  
    context.executeStrategy(); // 执行策略A  
  
    // 更改策略  
    context.setStrategy(&strategyB);  
    context.executeStrategy(); // 执行策略B  
  
    return 0;  
}
