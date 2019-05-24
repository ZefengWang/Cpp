#include <iostream>

#define SECOND2MINUTE (1.0/60.0)
#define MINUTE2DEGREE (1.0/60.0)

int main()
{
	using namespace std;
	int degree = 0, minute = 0, second = 0;
	double latitude = 0.0;
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl  \
		<< "First, enter the degrees: ";
	cin >> degree;
	cout << "Next, enter the minutes of arc: ";
	cin >> minute;
	cout << "Finally, enter the seconds of arc: ";
	cin >> second;

	latitude  = degree + minute * MINUTE2DEGREE + second * SECOND2MINUTE * MINUTE2DEGREE;
	cout << degree << " degrees, " << minute << " minutes, " << second \
		<< " seconds = " << latitude << " degress" << endl;
	return 0;
}
