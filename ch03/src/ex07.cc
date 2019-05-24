// mpg: miles / gallon
// European: liters / 100 km
// 100 km = 62.14 miles
// 1 gallon  = 3.875liters

// 1 mpg = 1 mile / 1 gallon = 1.0/62.14 / 3.875 (100km / liters)
#include <iostream>

#define FACTOR 62.14*3.875

int main()
{
	using namespace std;
	double EU = 0.0, US = 0.0;
	cout << "Enter an automobile gasoline consumption figure in the European style:\nliters per 100 kilometers: ______\b\b\b\b";
	cin >> EU;
	US = FACTOR/EU;
	cout << "U.S. style of miles per gallon: " << US <<" mpg" << endl; 
	return 0;
}
