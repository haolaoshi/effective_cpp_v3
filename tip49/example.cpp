#include <iostream>

void outOfMem()
{
	std::cerr<<"unable to satisfy\n";
	std::abort();
}


int main()
{
	std::set_new_handler(outOfMem);
	int* pBigData = new int[10000000000000L];

	return 0;
}
