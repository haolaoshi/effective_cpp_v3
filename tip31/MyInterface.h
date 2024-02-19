#ifndef MYINTERFACE_H
#define MYINTERFACE_H

#include <memory>

class MyInterfaceImpl;

class MyInterface
{
public:
	MyInterface();
	~MyInterface();

	void someFunction();
private:
	std::unique_ptr<MyInterfaceImpl> pimpl;
};


#endif
