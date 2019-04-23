#include <iostream>

void displaytime(int h, int m);

int main()
{
	using namespace std;
	int hour, minute;
	cout << "Enter the number of hours: ";
	cin >> hour;
	cout << "Enter the number of minutes: ";
	cin >> minute;
	hour %= 24;
	minute %= 60;
	displaytime(hour,minute);
	return 0;
}

void displaytime(int h, int m)
{
	using namespace std;
	cout << "Time: " << h << ":" << m << endl;
}
