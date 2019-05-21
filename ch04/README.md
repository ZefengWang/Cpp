# **Answer for ch04**
## **Summary**
---
1. Arrays, structures, and pointers are three C++ compound types. An array can hold several values, all of the same type, in a single data object. By using an index, or subscript, you can access the individual elements in an array.
2. A structure can hold several values of different types in a single data object, and you can use the membership operator ( . ) to access individual members. The first step in using structures is to create a structure template that defines what members the structure holds. The name, or tag, for this template then becomes a new type identifier.You can then declare structure variables of that type.
3. A union can hold a single value, but it can be of a variety of types, with the member name indicating which mode is being used.
4. Pointers are variables that are designed to hold addresses.We say a pointer points to the address it holds.The pointer declaration always states to what type of object a pointer points.Applying the dereferencing operator ( * ) to a pointer yields the value at the location to which the pointer points.
5. A string is a series of characters terminated by a null character.A string can be represented by a quoted string constant, in which case the null character is implicitly understood.You can store a string in an array of char , and you can represent a string with a pointer-to- char that is initialized to point to the string.The strlen() function returns the length of a string, not counting the null character.The strcpy() function copies a string from one location to another.When using these functions, you include the cstring or the string.h header file.
6. The C++ string class, supported by the string header file, offers an alternative, more user-friendly means to deal with strings. In particular, string objects are automatically resized to accommodate stored strings, and you can use the assignment operator to copy a string.
7. The new operator lets you request memory for a data object while a program is running.The operator returns the address of the memory it obtains, and you can assign that address to a pointer.The only means to access that memory is to use the pointer. If the data object is a simple variable, you can use the dereferencing operator ( * ) to indicate a value. If the data object is an array, you can use the pointer as if it were an array name to access the elements. If the data object is a structure, you can use the pointer dereferencing operator ( -> ) to access structure members.
8. Pointers and arrays are closely connected. If ar is an array name, then the expression ar[i] is interpreted as *(ar + i) , with the array name interpreted as the address of the first element of the array.Thus, the array name plays the same role as a pointer. In turn, you can use a pointer name with array notation to access elements in an array allocated by new .
9. The new and delete operators let you explicitly control when data objects are allocated and when they are returned to the memory pool. Automatic variables, which are those declared within a function, and static variables, which are defined outside a function or with the keyword static , are less flexible. An automatic variable comes into being when the block containing it (typically a function definition) is entered, and it expires when the block is left.A static variable persists for the duration of a program.
10. The Standard Template Library (STL), added by the C++98 standard, provides a vector template class that provides an alternative to do-it-yourself dynamic arrays. C++11 provides an array template class that offers an alternative to fixed-sized built-in arrays.
---
## **Chapter Review**
---
### 1. How would you declare each of the following?
```
a. actors is an array of 30 char .
b. betsie is an array of 100 short .
c. chuck is an array of 13 float .
d. dipsea is an array of 64 long double .
```
### 2. Does Chapter Review Question 1 use the array template class instead of built-in arrays.
### 3. Declare an array of five int s and initialize it to the first five odd positive integers.
### 4. Write a statement that assigns the sum of the first and last elements of the array in Question 3 to the variable even .
### 5. Write a statement that displays the value of the second element in the float array ideas .
### 6. Declare an array of char and initialize it to the string "cheeseburger" .
### 7. Declare a string object and initialize it to the string "Waldorf Salad" .
### 8. Devise a structure declaration that describes a fish.The structure should include the kind, the weight in whole ounces, and the length in fractional inches.
### 9. Declare a variable of the type defined in Question 8 and initialize it.
### 10. Use enum to define a type called Response with the possible values `Yes` , `No` , and `Maybe` . `Yes` should be `1` , `No` should be `0` , and `Maybe` should be `2` .
### 11. Suppose ted is a double variable. Declare a pointer that points to ted and use the pointer to display ted ’s value.
### 12. Suppose treacle is an array of 10 float s. Declare a pointer that points to the first element of treacle and use the pointer to display the first and last elements of the array.
### 13. Write a code fragment that asks the user to enter a positive integer and then creates a dynamic array of that many int s. Do this by using new , then again using a vector object.
### 14. Is the following valid code? If so, what does it print?
```
cout << (int *) “Home of the jolly bytes”;
```
### 15. Write a code fragment that dynamically allocates a structure of the type described in Question 8 and then reads a value for the kind member of the structure.
### 16. Listing 4.6 illustrates a problem created by following numeric input with line-oriented string input. How would replacing this: `cin.getline(address,80);` with this: `cin >> address;` affect the working of this program?
### 17. Declare a vector object of 10 string objects and an array object of 10 string objects. Show the necessary header files and don’t use `using` . Do use a `const` for the number of strings.
---
## **Programming Exercises**
---
### 1. Write a C++ program that requests and displays information as shown in the following example of output:
```
What is your first name? Betty Sue
What is your last name? Yewe
What letter grade do you deserve? B
What is your age? 22
Name: Yewe, Betty Sue
Grade: C
Age: 22
```
Note that the program should be able to accept first names that comprise more than one word.Also note that the program adjusts the grade downward—that is, up one letter.Assume that the user requests an A, a B, or a C so that you don’t have to worry about the gap between a D and an F.
```
```
### 2. Rewrite Listing 4.4, using the C++ string class instead of char arrays.
### 3. Write a program that asks the user to enter his or her first name and then last name, and that then constructs, stores, and displays a third string, consisting of the user’s last name followed by a comma, a space, and first name. Use char arrays and functions from the cstring header file.A sample run could look like this:
```
Enter your first name: Flip
Enter your last name: Fleming
Here’s the information in a single string: Fleming, Flip
```
```
```
### 4. Write a program that asks the user to enter his or her first name and then last name, and that then constructs, stores, and displays a third string consisting of the user’s last name followed by a comma, a space, and first name. Use string objects and methods from the string header file.A sample run could look like this:
```
Enter your first name: Flip
Enter your last name: Fleming
Here’s the information in a single string: Fleming, Flip
```
```
```
### 5. The CandyBar structure contains three members.The first member holds the brand name of a candy bar.The second member holds the weight (which may have a fractional part) of the candy bar, and the third member holds the number of calories (an integer value) in the candy bar.Write a program that declares such a structure and creates a CandyBar variable called snack , initializing its members to "Mocha Munch" , 2.3 , and 350 , respectively.The initialization should be part of the declaration for snack . Finally, the program should display the contents of the snack variable.
```
```
### 6. The CandyBar structure contains three members, as described in Programming Exercise 5. Write a program that creates an array of three CandyBar structures, initializes them to values of your choice, and then displays the contents of each structure.
```
```
### 7. William Wingate runs a pizza-analysis service. For each pizza, he needs to record the following information:
1. The name of the pizza company, which can consist of more than one word
2. The diameter of the pizza
3. The weight of the pizza
### Devise a structure that can hold this information and write a program that uses a structure variable of that type.The program should ask the user to enter each of the preceding items of information, and then the program should display that information. Use cin (or its methods) and cout .
```
```
### 8. Do Programming Exercise 7 but use new to allocate a structure instead of declaring a structure variable.Also have the program request the pizza diameter before it requests the pizza company name.
```
```
### 9. Do Programming Exercise 6, but instead of declaring an array of three CandyBar structures, use new to allocate the array dynamically.
```
```
### 10. Write a program that requests the user to enter three times for the 40-yd dash (or 40-meter, if you prefer) and then displays the times and the average. Use an array object to hold the data. (Use a built-in array if array is not available.)
```
```