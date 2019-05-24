#include <iostream>
#include <string>
int main()
{
	using namespace std;
	unsigned long long int world_p = 0, nation_p = 0;
	string nation;
	double percent = 0.0;
	cout << "Enter the nation you belong: ";
	cin >> nation;
	cout << "Enter the world's population: ";
	cin >> world_p;
	cout << "Enter the population of the " << nation <<": ";
	cin >> nation_p;
	percent = (double)nation_p / (double)world_p * 100.0;
	cout << "The population of the " << nation << " is " << percent \
		<< "% of the world population." << endl;
	return 0;
}
