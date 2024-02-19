#include "test.h"

Person::Person():name(""),address("")
{
	std::cout<<"default constructor of Person."<<std::endl;
}

//不是忘记定义析构，而是不需要定义 
Person::~Person()
{
	std::cout<<"virtual destructor of Person"<<std::endl;
}

Student::Student():schoolName(""),schoolAddress("")
{

	std::cout<<"Constructor to Student : default "<<std::endl;

}

Student::~Student()
{
  std::cout<<"desctruct in Student"<<std::endl;
}

bool validateStudent(Student& s)
{
	std::cout<<"yes , validation is pass."<<std::endl;
	return true;	
}

int main()
{
	Student plato;
	std::cout<<"----------------------"<<std::endl;

	bool isOk = validateStudent(plato);
	if(isOk)
	{
		std::cout<<" is Ok "<<std::endl;
	}

	std::cout<<"----------------------"<<std::endl;
	return 0;
}
