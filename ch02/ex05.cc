#include <iostream>

double cels2fahr(double cels);

int main()
{
	using namespace std;
	double cels = 0.0;
	cout << "Please enter a Celsius value: ";
	cin >> cels;
	cout << cels << " degrees Celsius is " << cels2fahr(cels) << " degrees Fahrenheit." << endl;

	return 0;
}

double cels2fahr(double cels)
{
	return cels*1.8 + 32.0;
}
