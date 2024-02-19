#include <iostream>

//策略类型定义，函数指针
typedef void(*Strategy)();

void StrategyA()
{
	std::cout<<"Executing strategy A"<<std::endl;
}

void StrategyB()
{
	std::cout<<"Executing Strategy B"<<std::endl;
}

class Context{
private:
	Strategy strategy;
public:
	void setStrategy(Strategy s)
	{
		strategy = s;
	}

	void executeStrategy(){
		if(strategy){
			strategy();
		}else{
			std::cout<<"no strategy set."<<std::endl;
		}
	}
};


int main()
{
	Context ctx;
	ctx.setStrategy(StrategyA);
	ctx.executeStrategy();

	ctx.setStrategy(StrategyB);
	ctx.executeStrategy();

	return 0;
}
