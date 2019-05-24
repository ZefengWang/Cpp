#include <iostream>

double ly2astron(double cels);

int main()
{
	using namespace std;
	double light_year = 0.0;
	cout << "Enter the number of light years: ";
	cin >> light_year;
	cout << light_year << " light years = " << ly2astron(light_year) << " astronomical units." << endl;

	return 0;
}

double ly2astron(double ly)
{
	return ly*63240.0;
}
