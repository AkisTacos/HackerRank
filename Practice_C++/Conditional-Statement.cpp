// Aki Saito
// HackerRank - Easy
// Conditional Statements
// April 3, 2019
// Language: C++
// 
/* Description:
	if and else are two of the most frequently used conditionals in C/C++, 
	and they enable you to execute zero or one conditional statement among 
	many such dependent conditional statements. We use them in the following ways:

		if: This executes the body of bracketed code starting with statement1
		if condition evaluates to true.

			if(condition) {
				statement1
				....
			}
		
		if - else: This executes the body of bracketed code starting with statement1
		if condition evaluates to true, or it executes the body of code starting 
		with statement2 if condition evaluates to false. 

		Note that only one of the bracketed code sections will ever be executed.

			if (condition) {
			    statement1;
			    ...
			}
			else {
			    statement2;
			    ...
			}

		if - else if - else: In this structure, dependent statements are chained 
		together and the condition for each statement is only checked if all 
		prior conditions in the chain evaluated to false. Once a condition evaluates 
		to true, the bracketed code associated with that statement is executed and 
		the program then skips to the end of the chain of statements and continues 
		executing. If each condition in the chain evaluates to false, then the 
		body of bracketed code in the else block at the end is executed.

			if(first condition) {
			    ...
			}
			else if(second condition) {
			    ...
			}
			.
			.
			.
			else if((n-1)'th condition) {
			    ....
			}
			else {
			    ...
			}
		
		Given a positive integer denoting n, do the following:
			- if 1 <= n <= 9, then print the lowercase English word corresponding 
			to the number (e.g., one for 1, two for 2, etc.)

			- if n > 9, print Greater than 9.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Write Your Code Here
    string numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if(n >= 1 && n <= 9)
    	cout << numbers[n-1];
    else
    	cout << "Greater than 9";

    return 0;
}





