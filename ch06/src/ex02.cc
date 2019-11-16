#include <iostream>
#include <array>
#include <string>
int main()
{
	using namespace std;
	array < double, 10 > arr;
	string str;
	for (int i = 0; i < 10; ++i)
	{
		cin >> str;
		cout << arr[i];
	}
	return 0;
}
