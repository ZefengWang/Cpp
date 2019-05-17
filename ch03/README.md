# Answer for ch03
## **Chapter Review**
### 1. Why does C++ have more than one integer type?
```
For different situation and chosing the right type to use
```
### 2. Declare variables matching the following descriptions:
```
a. A short integer with the value 80
b. An unsigned int integer with the value 42,110
c. An integer with the value 3,000,000,000
```
```
short int v1 = 80;` 
unnsigned int v2 =  42110;
```
~~`int v3 = 3000000000;`~~
```
unsigned int v3 = 3000000000;
```
### 3. What safeguards does C++ provide to keep you from exceeding the limits of an integer type?
``` 
unknown
```
### 4. What is the distinction between 33L and 33?
```
33L is storage in the long variable, 33 is int
```
### 5. Consider the two C++ statements that follow:
```
char grade = 65;
char grade = 'A';
```
### Are they equivalent?
~~`yes if we consider it in computer's eyesight`~~
```
not very the same, 65 is storaged as a int but 'A' is a char
```
### 6. How could you use C++ to find out which character the code 88 represents? Come up with at least two ways.
```
cout << char(88) << endl;

cout << (char)88 << endl;

char a = 88;
cout << a << endl;
```
### 7. Assigning a long value to a float can result in a rounding error.What about assigning long to double? long long to double?
```
unknown
```
### 8. Evaluate the following expressions as C++ would:
```
a. 8 * 9 + 2
b. 6 * 3 / 4
c. 3 / 4 * 6
d. 6.0 * 3 / 4
e. 15 % 4
```
```
a. 74
b. 6*3 -> 18 ; 18/4 -> 4;  res  --> 4
c. 0
d. 4.5
e. 3
```
### 9. Suppose x1 and x2 are two type double variables that you want to add as integers and assign to an integer variable. Construct a C++ statement for doing so.What if you want to add them as type double and then convert to int?
```
int c = int(x1) + int(x2);
int c = int (x1 + x2);
```
### 10. What is the variable type for each of the following declarations?
```
a. auto cars = 15;
b. auto iou = 150.37f;
c. auto level = 'B';
d. auto crat = U'/U00002155';
e. auto fract = 8.25f/2.5;
```
```
a. int
b. float
c. char
d. w_chat
e. double
```
## Programming Exercises
### 1. Write a short program that asks for your height in integer inches and then converts your height to feet and inches. Have the program use the underscore character to indicate where to type the response. Also use a const symbolic constant to represent the conversion factor.
```
#include <iostream>

int main()
{
	const double factor = 1.0/12;
	using namespace std;
	int height;
	cout << "Please input your height in inch: ___" << "\b\b\b";
	cin >> height;
	cout << "Your height in inches is: " << height          << "." << endl;
	cout << "Your height in feet   is: " << height * factor << "." << endl;

	return 0;
}
```

### 2. Write a short program that asks for your height in feet and inches and your weight in pounds. (Use three variables to store the information.) Have the program report your body mass index (BMI).To calculate the BMI, first convert your height in feet and inches to your height in inches (1 foot = 12 inches).Then convert your height in inches to your height in meters by multiplying by 0.0254.Then convert your weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute your BMI by dividing your mass in kilograms by the square of your height in meters. Use symbolic constants to represent the various conversion factors.
```
#include <iostream>

#define FOOT2INCH		12
#define INCH2METER		0.0254
#define POUND2KG		(1.0/2.2)

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

```
### 3. Write a program that asks the user to enter a latitude in degrees, minutes, and seconds and that then displays the latitude in decimal format.There are 60 seconds of arc to a minute and 60 minutes of arc to a degree; represent these values with symbolic constants.You should use a separate variable for each input value.A sample run should look like this:
```
Enter a latitude in degrees, minutes, and seconds:
First, enter the degrees: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
```
```
#include <iostream>

#define SECOND2MINUTE (1.0/60.0)
#define MINUTE2DEGREE (1.0/60.0)

int main()
{
        using namespace std;
        int degree = 0, minute = 0, second = 0;
        double latitude = 0.0;
        cout << "Enter a latitude in degrees, minutes, and seconds:" << endl  \
                << "First, enter the degrees: ";
        cin >> degree;
        cout << "Next, enter the minutes of arc: ";
        cin >> minute;
        cout << "Finally, enter the seconds of arc: ";
        cin >> second;

        latitude  = degree + minute * MINUTE2DEGREE + second * SECOND2MINUTE * MINUTE2DEGREE;
        cout << degree << " degrees, " << minute << " minutes, " << second \
                << " seconds = " << latitude << " degress" << endl;
        return 0;
}

```
### 4. Write a program that asks the user to enter the number of seconds as an integer value (use type long, or, if available, long long) and that then displays the equivalent time in days, hours, minutes, and seconds. Use symbolic constants to represent the number of hours in the day, the number of minutes in an hour, and the number of seconds in a minute.The output should look like this:
```
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
```
```
#include <iostream>

#define HOURINDAY               24
#define MINUTEINHOUR            60
#define SECONDINMINUTE          60

int main()
{
        using namespace std;
        unsigned long long int seconds = 0, days = 0, hour = 0, minute = 0, second = 0;
        cout << "Enter the number of seconds: ";
        cin >> seconds;
        second = seconds % SECONDINMINUTE;
        minute = seconds / SECONDINMINUTE;

        hour = minute / MINUTEINHOUR;
        minute %= MINUTEINHOUR;

        days = hour / HOURINDAY;
        hour %= HOURINDAY;
        cout << seconds << " seconds = " << days << " days, " << hour << " hours, "\
                << minute <<" minutes, " << second << "seconds" << endl;
        return 0;
}

```
### 5. Write a program that requests the user to enter the current world population and the current population of the U.S. (or of some other nation of your choice). Store the information in variables of type long long. Have the program display the percent that the U.S. (or other nation’s) population is of the world’s population.The output should look something like this:
```
Enter the world's population: 6898758899
Enter the population of the US: 310783781
The population of the US is 4.50492% of the world population.
```
### You can use the Internet to get more recent figures.
```
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	unsigned long long int world_p = 0, nation_p = 0;
	string nation;
	double percent = 0.0;
	cout << "Enter the nation you belong: ";
	cin >> nation;
	cout << "Enter the world's population: ";
	cin >> world_p;
	cout << "Enter the population of the " << nation <<": ";
	cin >> nation_p;
	percent = (double)nation_p / (double)world_p * 100.0;
	cout << "The population of the " << nation << " is " << percent \
		<< "% of the world population." << endl;
	return 0;
}

```
### 6. Write a program that asks how many miles you have driven and how many gallons of gasoline you have used and then reports the miles per gallon your car has gotten. Or, if you prefer, the program can request distance in kilometers and petrol in liters and then report the result European style, in liters per 100 kilometers
```
#include <iostream>

int main()
{
	using namespace std;
	double miles = 0.0, gallons = 0.0, report = 0.0;
	cout << "Enter the miles your car has driven: ";
	cin >> miles;
	cout << "Enter the gallons your car used: ";
	cin >> gallons;
	report = miles / gallons;
	cout << "Reports: " << report << " miles per gallon your car has gotten." << endl;
	return 0;
}
```

### 7. Write a program that asks you to enter an automobile gasoline consumption figure in the European style (liters per 100 kilometers) and converts to the U.S. style of miles per gallon. Note that in addition to using different units of measurement, the U.S. approach (distance / fuel) is the inverse of the European approach (fuel / distance). Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters.Thus, 19 mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km.
```
// mpg: miles / gallon
// European: liters / 100 km
// 100 km = 62.14 miles
// 1 gallon  = 3.875liters

// 1 mpg = 1 mile / 1 gallon = 1.0/62.14 / 3.875 (100km / liters)
#include <iostream>

#define FACTOR 62.14*3.875

int main()
{
	using namespace std;
	
	double EU = 0.0, US = 0.0;
	
	return 0;
}
```

