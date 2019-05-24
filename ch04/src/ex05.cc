#include <string>
#include <iostream>

struct CandyBar
{
    std::string branch;
    double weight;
    int calories;
};

int main()
{
    using namespace std;
    CandyBar snack {"Mocha Munch" , 2.3 , 350};
    cout << "Branch: " << snack.branch << endl
         << "Weight: " << snack.weight << endl
         << "Calories: " << snack.calories << endl;
    return 0;
}