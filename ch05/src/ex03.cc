#include <iostream>

int main()
{
	using namespace std;
	long long int input = 0;
	long double sum = 0.0;
	std::cout << std::fixed;
	std::cout.precision(0);
	do
	{   
		sum += input;
		cout << "Current Sum is: " << sum << endl << "Enter a number: ";
		cin >> input;
	}
	while (input != 0LL);
	return 0;
}
