// address.cpp -- using the & operator to find addresses
// the os is centos 7 and the space of variables in stack is not continusly
#include <iostream>
int main()
{
	using namespace std;
	int donuts = 6;
	double cups = 4.5;
	cout << "donuts value = " << donuts;
	cout << " and donuts address = 0x" << &donuts << " next value is: " << (double)*((double *)((char *)&donuts - 12)) << " sizeof donuts: " << sizeof(donuts) <<endl;
	// NOTE: you may need to use unsigned (&donuts)
	// and unsigned (&cups)
	cout << "cups   value = " << cups;
	cout << " and cups address = " << &cups << " sizeof cups:   " << sizeof(cups) <<endl;
	cout << "offset of two address: " /*<< hex*/ << (long long int)&donuts - (long long int)&cups << endl;
	return 0;
}
