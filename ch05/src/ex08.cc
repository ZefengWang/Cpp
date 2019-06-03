#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	char str [40] = {0};
	int total = 0;
	cout << "Enter words (to stop, type the word done):" << endl;
	do
	{
		cin >> str;
		total ++;
	}while (strcmp(str,"done"));
	total --;	
	cout << "You entered a total of " << total << " words." << endl;
	return 0;
}
