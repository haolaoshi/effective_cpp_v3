#include <iostream>
#include <functional>

using Strategy = std::function<void()>;

struct StrategyA{
	void operator()()const {
		std::cout<<"Executing strategy A"<<std::endl;
	}
};

struct StrategyB{
	void operator()() const{
		std::cout<<"Executing strategy B"<<std::endl;
	}

};

class Context{
private:
	Strategy strategy;
public:
	void setStrategy(const Strategy& s){
		strategy = s;
	}

	void executeStrategy(){
		if(strategy){
			strategy();
		}else{
			std::cout<<"No strategy."<<std::endl;
		}
	}
};


int main()
{
	Context ctx;
	ctx.setStrategy(StrategyA());
	ctx.executeStrategy();


	ctx.setStrategy(StrategyB());
	ctx.executeStrategy();

	ctx.setStrategy([](){
		std::cout<<"Executing lambda strategy"<<std::endl;
	});
	ctx.executeStrategy();

	return 0;
}
