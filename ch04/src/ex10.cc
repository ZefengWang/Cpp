#include <iostream>
#include <array>

int main()
{
    using namespace std;
    array<double,3> arr;
    double avr = 0.0;
    for (int i = 0; i < arr.size(); i ++)
    {
        cout << "Enter " << i+1 << "th dash: ";
        cin >> arr[i];
        avr += arr[i];
    }
    avr /=arr.size();
    for (int i = 0; i < arr.size(); i ++)
    {
        cout << i+1 << "th dash: " << arr[i] << endl;
    }
    cout << "average: " << avr << endl;
    return 0;
}
