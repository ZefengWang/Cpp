# Answer for ch02

## Chapter Review
### 1.What are the modules of C++ programs called?
### **Ans:** 
*Functions*
### 2. What does the following preprocessor directive do? 
```
#include <iostream>
```
#### **ans:** 
*Copy or replace the text of file `iostream` to the source file in preprocessing*
### 3. What does the following statement do? 
```
using namespace std;
```
### **ans:**
*Import the namespace std make some object which are belong to std available*
### 4. What statement would you use to print the phrase “Hello, world” and then start a new line?
### **ans:**
```
std::cout << "hello, world" << std::endl;
```
### 5. What statement would you use to create an integer variable with the name cheeses ?
### **ans:**
```
int cheeses = 0;
```
### 6. What statement would you use to assign the value 32 to the variable cheeses ?
### **ans:**
```
cheeses = 32;
```
### 7. What statement would you use to read a value from keyboard input into the variable cheeses ?
### **ans:**
```
std::cin >> cheeses;
```
### 8. What statement would you use to print “We have X varieties of cheese,” where the current value of the cheeses variable replaces X ?
### **ans:**
```
std::cout << "We have " << X << " varieties of cheese" <<std::endl;
```
### 9. What do the following function prototypes tell you about the functions?
```
int froop(double t);
void rattle(int n);
int prune(void);
```
### **ans:**
*Function `froop()` accept a parameter from double and return a int value*
*rattle `accept()` a integer variable and don\'t return a value*
*prune `accept()` none paramters and return a int value*
### 10. When do you not have to use the keyword `return` when you define a function?
### **ans:**
*When you statment a function with return type `void`*
### 11. Suppose your `main()` function has the following line: 
```
cout << “Please enter your PIN: “;
```
### And suppose the compiler complains that cout is an unknown identifier. What is the likely cause of this complaint, and what are three ways to fix the problem?
### **ans:**
*You didn't import the namespace std*
```
using namespace std;
using std::cout;
std::cout << “Please enter your PIN: “;
```

## Programming Exercises
### 1. Write a C++ program that displays your name and address (or if you value your privacy, a fictitious name and address).
### **ans:**
```
#include <iostream>

int main()
{
	using std::cout;
	cout << "Address : beijing!\nName    : wangzefeng\n" ;
	return 0;
}
```
### 2. Write a C++ program that asks for a distance in furlongs and converts it to yards. (One furlong is 220 yards.)
### **ans:**
```
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int furlongs;
	cout << "Please input a num. (unit furlongs)" << endl;
	cin >> furlongs;
	cout << furlongs << " furlongs is equels to value " << furlongs * 220 << " yards." << endl;
	return 0;
}
```
### 3. Write a C++ program that uses three user-defined functions (counting `main()` as one) and produces the following output:
```
Three blind mice
Three blind mice
See how they run
See how they run
```
### One function, called two times, should produce the first two lines, and the remaining function, also called twice, should produce the remaining output.
### **ans:**
```
#include <iostream>

void func1();
void func2();

int main()
{
	func1();
	func1();
	func2();
	func2();
	return 0;
}

void func1()
{
	using namespace std;
	cout << "Three blind mice" << endl;
}

void func2()
{
	using namespace std;
	cout << "See how they run" << endl;
}

```
### 4. Write a program that asks the user to enter his or her age.The program then should display the age in months:
```
Enter your age: 29
Your age in months is 384.
```
### **ans:**
```
#include <iostream>

int main()
{
	using namespace std;
	int age = 0;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Your age in months is " << age * 12 << ".\n";
	return 0;
}

```
### 5. Write a program that has `main()` call a user-defined function that takes a Celsius temperature value as an argument and then returns the equivalent Fahrenheit value. The program should request the Celsius value as input from the user and display the result, as shown in the following code:
```
Please enter a Celsius value: 20
20 degrees Celsius is 68 degrees Fahrenheit.
For reference, here is the formula for making the conversion:
Fahrenheit = 1.8 × degrees Celsius + 32.0
```
### **ans:**
```
#include <iostream>

double cels2fahr(double cels);

int main()
{
	using namespace std;
	double cels = 0.0;
	cout << "Please enter a Celsius value: ";
	cin >> cels;
	cout << cels << " degrees Celsius is " << cels2fahr(cels) << " degrees Fahrenheit." << endl;

	return 0;
}

double cels2fahr(double cels)
{
	return cels*1.8 + 32.0;
}

```
### 6. Write a program that has `main()` call a user-defined function that takes a distance in light years as an argument and then returns the distance in astronomical units. The program should request the light year value as input from the user and display the result, as shown in the following code:
```
Enter the number of light years: 4.2
4.2 light years = 265608 astronomical units.
```
### An astronomical unit is the average distance from the earth to the sun (about 150,000,000 km or 93,000,000 miles), and a light year is the distance light travels in a year (about 10 trillion kilometers or 6 trillion miles). (The nearest star after the sun is about 4.2 light years away.) Use type double (as in Listing 2.4) and this conversion factor:
### 1 light year = 63,240 astronomical units
### **ans:**
```

```
### 7. Write a program that asks the user to enter an hour value and a minute value.The `main()` function should then pass these two values to a type `void` function that displays the two values in the format shown in the following sample run:
```
Enter the number of hours: 9
Enter the number of minutes: 28
Time: 9:28
```
### **ans:**
```

```
