#include <iostream>
#include <vector>

class ImplicitInterface{
public:
	virtual ~ImplicitInterface(){};
	virtual void print() const = 0;//纯虚，定义隐式接口
};

class MyClass : public ImplicitInterface{
public:
	void print() const override{
		std::cout<<"My Class :: print()"<<std::endl;
	}
};

template<typename T>
void printObjects(const std::vector<T>& objects){
	for(const auto& obj: objects){
		obj->print();
	}
}

int main()
{
	std::vector<ImplicitInterface*> objs;
	objs.push_back(new MyClass());
	
	printObjects(objs);

	for(auto* obj: objs)
	{
		delete obj;
	}

	return 0;
}
