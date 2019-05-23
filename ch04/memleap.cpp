#include <iostream>
#include <unistd.h>

int main()
{
	using namespace std;
	int *p;
	cout <<  "\e[1;31mWARNING: The program can cause your computer's memery leap, BE CAREFUL\e[0m" << endl;
	while (true)
	{
		usleep(1);
		for (int i = 0; i < 5000; ++i)
		p=new int;
	}
	return 0;
}
