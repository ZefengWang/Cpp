#include <string>
#include <iostream>

struct Pizza
{
	std::string company;
	float diameter;
	float weight;
};

int main()
{
	using namespace std;
	Pizza *pizza = new Pizza;

	cout << "Enter the company: ";
	cin >> pizza->company;
	cout << "Enter the diameter: ";
	cin >> pizza->diameter;
	cout << "Enter the weight: ";
	cin >> pizza->weight;


	cout << "The company is: " << pizza->company << endl
		<< "The diameter is : " << pizza->diameter << endl
		<< "The weight is : " << pizza->weight << endl;

	return 0;
}
