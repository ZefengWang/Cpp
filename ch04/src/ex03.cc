#include <cstring>
#include <iostream>

#define BUFFSIZE 80
int main()
{
    using namespace std;
    char firstname [BUFFSIZE];
    char lastname  [BUFFSIZE];
    char full [BUFFSIZE+BUFFSIZE] {0};
    cout << "Enter your first name: ";
    cin.get(firstname, BUFFSIZE).get();
    cout << "Enter your last  name: ";
    cin.get(lastname,  BUFFSIZE).get();
    if (NULL == strncat(full,lastname,BUFFSIZE))
    {
        cout << "\e[1;31merror: \e[0mstrncat" << endl;
        exit(0);
    }
    if (NULL == strncat(full,", ",3))
    {
        cout << "\e[1;31merror: \e[0mstrncat" << endl;
        exit(0);
    }
    if (NULL == strncat(full,firstname,BUFFSIZE))
    {
        cout << "\e[1;31merror: \e[0mstrncat" << endl;
        exit(0);
    }
    cout << "Here’s the information in a single string: " << full << endl;
    return 0;
}