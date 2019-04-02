// Aki Saito
// HackerRank - Easy
// Basic Data Types
// April 1, 2019
// Language: C++
// 
/* Description:
	Some C++ data types, their format specifiers, and their most 
	common bit widths are as follows:

	Int ("%d"): 32 Bit integer
	Long ("%ld"): 64 bit integer
	Char ("%c"): Character type
	Float ("%f"): 32 bit real value
	Double ("%lf"): 64 bit real value

	Reading:

	To read a data type, use the following syntax:
	scanf("`format_specifier`", &variableName)

	Printing:

	To print a data type, use the following syntax:
	printf("`format_specifier`", variableName)
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.

    // Read data
    int numInt; // "%d" 
    long numLng; // "%ld"
    char wordChar; // "%c"
    float numFlt; // "%f"
    double numDbl; // "%lf"

    scanf("%d %ld %c %f %lf", &numInt, &numLng, &wordChar, &numFlt, &numDbl);
    printf("%d \n%ld \n%c \n%f \n%lf", numInt, numLng, wordChar, numFlt, numDbl);

    return 0;
}