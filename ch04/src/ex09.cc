#include <string>
#include <iostream>

struct CandyBar
{
	std::string branch;
	double weight;
	int calories;
};

int main()
{
	using namespace std;
	CandyBar *snack = new CandyBar [3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the " << i <<"th branch: ";
		cin >> snack[i].branch;
		cout << "Enter the " << i <<"th weight: ";
		cin >> snack[i].weight;
		cout << "Enter the " << i <<"th calories: ";
		cin >> snack[i].calories;
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "The " << i << "th Branch: " << snack[i].branch << endl
			<< "The " << i << "th Weight: " << snack[i].weight << endl
			<< "The " << i << "th Calories: " << snack[i].calories << endl << endl;
	}
	delete [] snack;
	return 0;
}
