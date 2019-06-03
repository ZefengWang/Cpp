#include <iostream>

const double sim = 0.10, com = 0.05;
int main()
{
	using namespace std;
	double simple = 100.0, compound = 100.0;
	int year = 0;
	std::cout.precision(2);
	while ( compound <= simple )
	{
		simple += 100*sim;
		compound += compound*com;
		year ++;
	}
	std::cout << std::fixed << "year is: " << year << endl;
	std::cout << "Daphne's interest is: " << simple << endl;
	std::cout << "Cleo's interest is: " << compound << endl;
	return 0;
}
