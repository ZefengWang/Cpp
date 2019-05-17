#include <iostream>

#define FOOT2INCH	12
#define INCH2METER	0.0254
#define POUND2KG	(1.0/2.2)

int main(int argc, char ** argv)
{
	using namespace std;
	double h_f = 0, h_i = 0;
	double h_m = 0.0, w_p = 0.0, w_kg = 0.0, BMI = 0.0;
	cout << "Please input you height in foot part: ___\b\b";
	cin >> h_f;
	cout << "Please input you height in inch part: ___\b\b";
	cin >> h_i;
	cout << "Please input you weight in pound: _____\b\b\b\b";
	cin >> w_p;

	h_i += h_f * FOOT2INCH;
	h_m = h_i * INCH2METER;
	w_kg = w_p * POUND2KG;

	BMI = w_kg / (h_m * h_m);
	cout << "\e[1;32mHere is your Result:\e[0m\n\tYour Height is: " <<  h_m \
		<< "meters. \n\tYour weight is: " << w_kg << "kg." \
		<< "\n\tYour BMI index is: " << BMI << endl;
	return 0;
}
