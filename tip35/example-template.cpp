#include <iostream>

//NVI
class Shape{
public:
	void draw(){
		doDraw();
	}
protected:
	virtual void doDraw() = 0;
};

//Template Method 
class Circle : public Shape{
protected:
	void doDraw() override{
		std::cout<<"Drawing a circle."<<std::endl;
	}
};

class Rectangle : public Shape{
protected:
	void doDraw() override{
		std::cout<<"Drawing a rect."<<std::endl;
	}
};


int main()
{
//NVI obj, puliic method 
	Shape* circle = new Circle();
	circle->draw();
	
	return 0;
}
