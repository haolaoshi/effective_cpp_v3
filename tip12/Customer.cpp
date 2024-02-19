#include "Customer.h"

Customer::Customer(const Customer& c):name(c.name)
{
}

Customer&
Customer::operator=(const Customer& rhs)
{
	this->name = rhs.name;
	return *this;
}

int main()
{

	return 0;
}
