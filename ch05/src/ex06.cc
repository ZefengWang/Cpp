#include <iostream>
#include <string>
const int months = 12, years = 3;
int main()
{
	using namespace std;
	string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int sell[years][months] = {0}, total[years] = {0}, total_y = 0;

	for (int year = 0; year < years; ++year)
	{
		for (int i = 0; i < months; ++i)
		{
			cout << "Enter sell number of " << month[i] << " in year " << year + 1 << ": ";
			cin >> sell[year][i];
			total[year] += sell[year][i];
		}
		total_y += total[year];
	}
	for (int i = 0; i < years; ++i)
		std::cout << "Total sell in year " << i + 1 << " is: " << total[i] << endl;
	std::cout << "Total sell is: " << total_y << endl;
	return 0;
}
