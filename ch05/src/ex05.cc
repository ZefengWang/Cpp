#include <iostream>
#include <string>
const int months = 12;
int main()
{
	using namespace std;
	string month [] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int sell[months] = {0}, total = 0;
	for(int i = 0; i < months; ++i)
	{
		cout << "Enter sell number of " << month[i] << ": ";
		cin >> sell[i];
		total += sell[i];
	}
	std::cout << "Total sell is: " << total << endl;
	return 0;
}
