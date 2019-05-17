#include <iostream>

int main()
{
	using namespace std;
	double miles = 0.0, gallons = 0.0, report = 0.0;
	cout << "Enter the miles your car has driven: ";
	cin >> miles;
	cout << "Enter the gallons your car used: ";
	cin >> gallons;
	report = miles / gallons;
	cout << "Reports: " << report << " miles per gallon your car has gotten." << endl;
	return 0;
}
