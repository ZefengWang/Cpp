#include <string>
#include <iostream>

int main()
{
    using namespace std;
    string firstname, lastname, full;
    cout << "Enter your first name: ";
    (cin >> firstname).get();
    cout << "Enter your last  name: ";
    (cin >> lastname).get();
    full = lastname + ", " + firstname;
    cout << "Here’s the information in a single string: " << full << endl;
    return 0;
}