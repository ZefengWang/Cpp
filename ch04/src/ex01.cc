#include <iostream>
#include <vector>
#include <string>
struct student
{
    std::string firstname;
    std::string lastname;
    char grade;
    int age;
};
int main()
{
    using namespace std;
    student *ss = new student;
    cout << "What is your first name? ";
    cin >> ss->firstname;
    cout << "What is your last  name? ";
    cin >> ss->lastname;
    cout << "What letter grade do you deserve? ";
    cin >> ss->grade;
    ss->grade ++;
    cout << "What is your age? ";
    cin >> ss->age;

    cout << "Name:  " << ss->lastname << ", " << ss->firstname << endl;
    cout << "Grade: " << ss->grade  << endl;
    cout << "Age: " << ss->age << endl;
    delete ss;
    return 0;
}