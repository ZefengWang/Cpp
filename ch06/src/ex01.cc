#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	int  ch;
	ch = cin.get();
	while( ch != '@')
	{
		if (isdigit(ch) != 0)
		{
			ch = cin.get();
			continue;
		}
		else if (isupper(ch))
		{
			cout << char(tolower(ch));
		} 
		else if (islower(ch))
		{
			cout << char(toupper(ch));
		}
		else 
		{
			cout << char(ch);
		}
		ch = cin.get();
	}
	return 0;
}

