# Summary
---
### C++ offers three varieties of loops: for loops, while loops, and do while loops.A loop cycles through the same set of instructions repetitively, as long as the loop test condition evaluates to true or nonzero and the loop terminates execution when the test condition evaluates to false or zero.The for loop and the while loop are entry-condition loops, meaning that they examine the test condition before executing the statements in the body of the loop.The do while loop is an exit-condition loop, meaning that it examines the test condition after executing the statements in the body of the loop.

### The syntax for each loop calls for the loop body to consist of a single statement. However, that statement can be a compound statement, or block, formed by enclosing several statements within paired curly braces.

### Relational expressions, which compare two values, are often used as loop test conditions. Relational expressions are formed by using one of the six relational operators: < , <= , == , >= , > , or != . Relational expressions evaluate to the type bool values true and false .

### Many programs read text input or text files character-by-character.The istream class provides several ways to do this. If ch is a type char variable, the following statement reads the next input character into ch :
```
cin >> ch;
```

### However, it skips over spaces, newlines, and tabs.The following member function call reads the next input character, regardless of its value, and places it in ch :
```
cin.get(ch);
```

### The member function call cin.get() returns the next input character, including spaces, newlines, and tabs, so it can be used as follows:
```
ch = cin.get();
```

### The cin.get(char) member function call reports encountering the EOF condition by returning a value with the bool conversion of false , whereas the cin.get() member function call reports the EOF by returning the value EOF , which is defined in the iostream file.

### A nested loop is a loop within a loop. Nested loops provide a natural way to process two-dimensional arrays.

Chapter Review
---
### 1. What’s the difference between an entry-condition loop and an exit-condition loop? Which kind is each of the C++ loops?
### 2. What would the following code fragment print if it were part of a valid program?
``` cpp
int i;
for (i = 0; i < 5; i++)
cout << i;
cout << endl;
```
### 3. What would the following code fragment print if it were part of a valid program?
```cpp
int j;
for (j = 0; j < 11; j += 3)
cout << j;
cout << endl << j << endl;
```
### 4. What would the following code fragment print if it were part of a valid program?
```cpp
int j = 5;
while ( ++j < 9)
cout << j++ << endl;
```
### 5. What would the following code fragment print if it were part of a valid program?
```cpp
int k = 8;
do
cout <<" k = " << k << endl;
while (k++ < 5);
```
### 6. Write a for loop that prints the values 1 2 4 8 16 32 64 by increasing the value of a counting variable by a factor of two in each cycle.
### 7. How do you make a loop body include more than one statement?
### 8. Is the following statement valid? If not, why not? If so, what does it do?
```cpp
int x = (1,024);
```
What about the following?
```cpp
int y;
y = 1,024;
```
### 9. How does cin>>ch differ from cin.get(ch) and ch=cin.get() in how it views input?