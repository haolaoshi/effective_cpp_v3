#include <iostream>
#include <vector>

//// 隐式接口：只要一个类提供了print成员函数，就可以被视为实现了该接口 
class ImplicitInterface{
public:
	virtual ~ImplicitInterface(){};
	virtual void print() const = 0;//纯虚，定义隐式接口
};
//这个类实现了隐式接口
class MyClass : public ImplicitInterface{
public:
	void print() const override{
		std::cout<<"My Class :: print()"<<std::endl;
	}
};
//// 编译期多态，通过函数模板实现
template<typename T>
void printObjects(const std::vector<T>& objects){
	for(const auto& obj: objects){
		obj->print();//调用对象的成员函数 ，实现多态
	}
}

int main()
{
	std::vector<ImplicitInterface*> objs;
	objs.push_back(new MyClass());
//	编译期多态，通过函数模板实现	
	printObjects(objs);

	for(auto* obj: objs)
	{
		delete obj;
	}

	return 0;
}
