#include <iostream>
#include <vector>
int main()
{
    using namespace std;
    int size;
    cout << "Enter a number size of array: ";
    cin >> size;
    int * s1 = new int [size];
    
    vector<int> s2(size);
    delete [] s1;
    return 0;
}