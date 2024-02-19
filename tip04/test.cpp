#include <iostream>
#include <memory>


class Foo{
double some_var ; 
public:
	Foo(const double var):some_var(var){}

	double Bar(double d)
	{
		static double i = d;
		some_var = i;	
		return some_var;
	}

};

void counter(){
	static int call_count = 0;
	++call_count ; 

	std::cout<<" Func "<<call_count<<std::endl;

}

int main()
{


	for(double i = 1.0;  i < 100; i += 1.0)
	{
//		std::shared_ptr<Foo> f = std::make_shared<Foo>(i);	
//		std::shared_ptr<Foo> ptr(new Foo(i));
//
//		std::cout<<"d = "<<f->Bar(i)<<",i="<<ptr->Bar(i)<<std::endl;
		counter();
	}
	return 0;
}
