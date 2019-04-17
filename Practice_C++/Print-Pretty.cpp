// Aki Saito
// HackerRank - Easy
// Print Pretty
// April 16, 2019
// Language: C++
// Credits to cian_j_mcintyre for help
/* Description:
    
    Your manager gave you a text file with many lines of numbers to format and print.
    For each row of 3 space-separated doubles, format and print the numbers using
    the specifications in the Output Format section below.
	
	cout << hex;  		  	 // Output the number in hexadecimal format
	cout << dec;			 // Output the numbers in decimal format
	
	cout << left; 		  	 // Align the number to the left
	cout << right;		  	 // Align the numbers to right
	
	cout << setw(15);	  	 // Sets a fixed width of 15 with default " "
	cout << setfill('_'); 	 // Changes setw fill from " " to "_"
	
	cout << showpos;		 // Adds '+' to any positive number
	cout << noshowpos;		 // Removes '+' to any positive number

	cout << fixed;			 // Numbers are printed out entirely and 
							 // no scientific notation is used for large numbers
	
	cout << setprecision(2); // Sets the number of decimal places

	cout << showbase;		 // Shows 0x before hexadecimal to ensure base
	
	cout << nouppercase;	 // Converts all alphabetic values are lowercase
	cout << uppercase;		 // Converts all alphabetic values are uppercase

*/

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */

		// Format output
		cout << hex << left << showbase << nouppercase; 
		// Print after formatting
		cout << (long long) A << endl; 

		// Format output
		cout << dec << right << setw(15) << setfill('_') << showpos << fixed
		<< setprecision(2);
		// Print
		cout << B << endl;

		//Format output
		cout << scientific << uppercase << noshowpos << setprecision(9);
		// Print
		cout << C << endl;

	}
	return 0;

}