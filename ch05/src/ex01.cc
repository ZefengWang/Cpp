#include <iostream>

int main()
{
	using namespace std;
	unsigned long long int first, second, total = 0, temp;
	cout << "Enter first  number: ";
	cin >> first;
	cout << "Enter second number: ";
	cin >> second;
	if (first > second) {
		temp = first;
		first = second;
		second = temp;
	}
	for (unsigned long long int i = first; i <= second; ++i )
		total +=i;
	cout << "Sum of " << first << "~" << second << " is: " << total << endl;
	return 0;
}
