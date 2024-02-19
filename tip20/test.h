#include <string>
#include <iostream>


class Person{
public:
	Person();
	virtual ~Person();
	Person(const Person& p)
	{
		if(this == &p) return ;
		name = p.name;
		address = p.address;
		std::cout<<"Person Invoke copy assignement."<<std::endl;
	}
private:
	std::string name;
	std::string address;

};

class Student : public Person{
public:
	Student();
	~Student();
	//copy constructor
	Student(const Student& s):Person(s){
		if(this == &s) return;
		schoolName = s.schoolName;
		schoolAddress = s.schoolAddress;	
		std::cout<<"Invoke Student 's copy assignment"<<std::endl;
	}
private:
	std::string schoolName;
	std::string schoolAddress;
};
