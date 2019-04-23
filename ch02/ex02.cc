#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int furlongs;
	cout << "Please input a num. (unit furlongs)" << endl;
	cin >> furlongs;
	cout << furlongs << " furlongs is equels to " << furlongs * 220 << " yards." << endl;
	return 0;
}
