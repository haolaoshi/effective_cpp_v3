#include "MyInterface.h"
#include "MyInterfaceImpl.h"

MyInterface::MyInterface():impl(std::make_unique<MyInterfaceImpl>()){}
MyInterface::~MyInterface() = default;

void MyInterface::someFunction()
{
	pimpl->someFunction();
}
