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

struct test
{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned char e;
	unsigned char f;
	unsigned char g;
	unsigned char h;
};

int main()
{
	std::cout << "addr of main: " << std::hex << (unsigned long int )&main << std::endl;
	test t1 {0x12,0x34,0x56,0x78,0x90,0xab,0xcd,0xef};
	std::cout << "t1, a,b,c,d,e,f,g,h: " 	<< std::hex << "\n" << (unsigned long int)&t1 << "\n" << (unsigned long int)&t1.a 
		<< "\n" << (unsigned long int)&t1.b << "\n"<< (unsigned long int)&t1.c <<"\n"<< (unsigned long int)&t1.d << "\n" << (unsigned long int)&t1.e 
		<< "\n" << (unsigned long int)&t1.f << "\n" << (unsigned long int)&t1.g << "\n" << (unsigned long int)&t1.h << std::endl;
	std::cout << std::hex << "value of t1: " << *(unsigned long int *)&t1 << std::endl;
	bitfield bit1 {true,2,3,3,127,0xbb,0x7fff,0x1ffff};
	std::cout << "sizeof bit1 is: " << sizeof bit1 << std::endl;
	std::cout << std::hex << std::endl;
	unsigned int * ptr = (unsigned int *) &bit1;
	*ptr &= 0xffffffff00ffffff;
	*ptr |= 0x00000000aa000000;
	std::cout << "0x" << std::hex<<(*(( int*)&bit1))     << " addr: " << &bit1       << std::endl;
	std::cout << "0x" << std::hex<<(*(( int*)&bit1 + 1)) << " addr: " << std::hex << (unsigned long)(&bit1.sev)  << std::endl;
	std::cout << "one is: 0x" <<std::hex<< (int)bit1.one <<std::endl;
	std::cout << "two is: 0x" <<std::hex<< (int)bit1.two <<std::endl;
	std::cout << "thr is: 0x" <<std::hex<< (int)bit1.thr <<std::endl;
	std::cout << "fou is: 0x" <<std::hex<< (int)bit1.fou <<std::endl;
	std::cout << "fiv is: 0x" <<std::hex<< (int)bit1.fiv <<std::endl;
	std::cout << "six is: 0x" <<std::hex<< (int)bit1.six <<std::endl;
	return 0;
}
