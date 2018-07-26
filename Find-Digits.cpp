// Aki Saito
// HackerRank - Easy
// Find Digits
// July 25, 2018
// Language: C++
// 
/* Description:

	An integer d is a divisor of an integer n if the remainder of n / d = 0.
	
	Given an integer, for each digit that makes up the integer determine whether it is a divisor. 
	Count the number of divisors occurring within the integer.
	
	Note: Each digit is considered to be unique, so each occurrence of the same digit should be counted 
	(e.g. for n = 111, 1 is a divisor of 111 each time it occurs so the answer is 3).
	
	Function Description
	
	Complete the findDigits function in the editor below. 
	It should return an integer representing the number of digits of d that are divisors of d.
	
	findDigits has the following parameter(s):
	n: an integer to analyze

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    
    int digit, result = 0;
    int number = n;
    while(number){
        digit = number % 10;
        if(digit != 0)
            if( (n % digit) == 0 )
                result += 1;
        number /= 10;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

