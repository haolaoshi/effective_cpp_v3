#include <string>

class Customer{
public:
	Customer(const Customer& c);
	Customer& operator=(const Customer& rhs);
private:
	std::string name;
	int lastCount;
};
