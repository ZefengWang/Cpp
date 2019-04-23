#include <iostream>

void func1();
void func2();

int main()
{
	func1();
	func1();
	func2();
	func2();
	return 0;
}

void func1()
{
	using namespace std;
	cout << "Three blind mice" << endl;
}

void func2()
{
	using namespace std;
	cout << "See how they run" << endl;
}
