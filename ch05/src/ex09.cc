#include <iostream>
#include <string>
int main()
{
	using namespace std;
	string str;
	int total = 0;
	cout << "Enter words (to stop, type the word done):" << endl;
	do
	{
		cin >> str;
		total ++;
	}while (str != "done");
	total --;	
	cout << "You entered a total of " << total << " words." << endl;
	return 0;
}
