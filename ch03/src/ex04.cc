#include <iostream>

#define HOURINDAY			24
#define MINUTEINHOUR		60
#define SECONDINMINUTE		60

int main()
{
	using namespace std;
	unsigned long long int seconds = 0, days = 0, hour = 0, minute = 0, second = 0; 
	cout << "Enter the number of seconds: ";
	cin >> seconds;
	second = seconds % SECONDINMINUTE;
	minute = seconds / SECONDINMINUTE;

	hour = minute / MINUTEINHOUR;
	minute %= MINUTEINHOUR;

	days = hour / HOURINDAY;
	hour %= HOURINDAY;
	cout << seconds << " seconds = " << days << " days, " << hour << " hours, "\
		<< minute <<" minutes, " << second << "seconds" << endl;
	return 0;
}
