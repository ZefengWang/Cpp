#include <iostream>

int main()
{
	std::cout << "sizeof bool is: " << sizeof(bool) << "  "<< bool(0x02) << std::endl;
	std::cout << "sizeof bool is: " << sizeof(bool) << std::endl;
	std::cout << "sizeof bool is: " << sizeof((bool)0xff) << std::endl;
	return 0;
}
