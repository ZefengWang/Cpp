#include <iostream>
#include <string>
struct Car
{
	std::string maker;
	int year;
};
int main()
{
	using namespace std;
	int nums = 0;
	cout << "How many cars do you wish to catalog? ";
	cin >> nums;
	Car * cars = new Car [nums];
	for (int i = 0; i < nums; ++i)
	{
		cout << "Car #" << i+1 << ":" << endl 
			<<  "Please enter the make: ";
		cin.get();	
		getline(cin,cars[i].maker);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
	}
	cout << "Here is your collection:" << endl;
	for (int i = 0; i < nums; ++i)
	{
		cout << cars[i].year << " " << cars[i].maker << endl;
	}

	return 0;
}
