#include <iostream>

struct bitfield
{
	unsigned char one:1;
	unsigned char two:2;
	unsigned char thr:3;
	unsigned char fou:2;
	unsigned char sev;
	unsigned char eig;
	unsigned int fiv:15;
	unsigned int six:17;
};

int main()
{
	bitfield bit1 {true,2,3,3,127,0xbb,0x7fff,0x1ffff};
	std::cout << "sizeof bit1 is: " << sizeof bit1 << std::endl;
	std::cout << std::hex << std::endl;
	unsigned int * ptr = (unsigned int *) &bit1;
	*ptr &= 0xffffffff00ffffff;
	*ptr |= 0x00000000aa000000;
	std::cout << "0x" <<std::hex<<(*(( int*)&bit1)) << std::endl;
	std::cout << "0x" <<std::hex<<(*(( int*)&bit1 + 1)) << std::endl;
	std::cout << "one is: 0x" <<std::hex<< (int)bit1.one << std::endl;
	std::cout << "two is: 0x" <<std::hex<< (int)bit1.two << std::endl;
	std::cout << "thr is: 0x" <<std::hex<< (int)bit1.thr << std::endl;
	std::cout << "fou is: 0x" <<std::hex<< (int)bit1.fou << std::endl;
	std::cout << "fiv is: 0x" <<std::hex<< (int)bit1.fiv << std::endl;
	std::cout << "six is: 0x" <<std::hex<< (int)bit1.six << std::endl;
	return 0;
}
