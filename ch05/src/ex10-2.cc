#include <iostream>
int main()
{
	using namespace std;
	int rows = 0;
	cout << "Enter number of rows: ";
	cin >> rows;
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = rows; j > i; j--)
			cout << '.';
		for (int j = 1; j < 2*i; j+=1)
			cout << '*';
		for (int j = rows; j > i; j--)
			cout << '.';
		cout << endl;	
	}
	return 0;
}
