#include <iostream>

int main()
{
	const double factor = 1.0/12;
	using namespace std;
	int height;
	cout << "Please input your height in inch: ___" << "\b\b\b";
	cin >> height;
	cout << "Your height in inches is: " << height          << "." << endl;
	cout << "Your height in feet   is: " << height * factor << "." << endl;

	return 0;
}
