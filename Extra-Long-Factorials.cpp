// Aki Saito
// HackerRank - Medium
// Find Digits
// July 25, 2018
// Language: C++
// 
/* Description:

	The factorial of the integer n, written n!, is defined as:

		n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1

	Calculate and print the factorial of a given integer.

	For example, if n = 30, we calculate 30 * 29 * 28 * ... * 2 * 1 
	and get 265252859812191058636308480000000.

	Function Description

	Complete the extraLongFactorials function in the editor below. 
	It should print the result and return.
	extraLongFactorials has the following parameter(s):

		n: an integer

	Note: Factorials of n > 20 can't be stored even in a 64 - bit long long variable. 
	Big integers must be used for such calculations. 
	Languages like Java, Python, Ruby etc. can handle big integers, 
	but we need to write additional code in C/C++ to handle huge values.
	
	We recommend solving this challenge using BigIntegers.

*/

#include <bits/stdc++.h>
using namespace std;
// Helper Functions from https://github.com/panks/BigInteger/blob/master/BigInteger.cpp
// Altered a little to be able to use in our problem

string addThis(string number1, string number2)
{
    string add = (number1.length() > number2.length()) ?  number1 : number2;
    char carry = '0';
    int differenceInLength = abs( (int) (number1.size() - number2.size()) );

    if(number1.size() > number2.size())
        number2.insert(0, differenceInLength, '0'); // put zeros from left

    else// if(number1.size() < number2.size())
        number1.insert(0, differenceInLength, '0');

    for(int i=number1.size()-1; i>=0; --i)
    {
        add[i] = ((carry-'0')+(number1[i]-'0')+(number2[i]-'0')) + '0';

        if(i != 0)
        {    
            if(add[i] > '9')
            {
                add[i] -= 10;
                carry = '1';
            }
            else
                carry = '0';
        }
    }
    if(add[0] > '9')
    {
        add[0]-= 10;
        add.insert(0,1,'1');
    }
    return add;
}

string multiplyThis(string n1, string n2)
{
    if(n1.length() > n2.length()) 
        n1.swap(n2);

    string res = "0";
    for(int i=n1.length()-1; i>=0; --i)
    {
        string temp = n2;
        int currentDigit = n1[i]-'0';
        int carry = 0;

        for(int j=temp.length()-1; j>=0; --j)
        {
            temp[j] = ((temp[j]-'0') * currentDigit) + carry;

            if(temp[j] > 9)
            {
                carry = (temp[j]/10);
                temp[j] -= (carry*10);
            }
            else
                carry = 0;

            temp[j] += '0'; // back to string mood
        }

        if(carry > 0)
            temp.insert(0, 1, (carry+'0'));
        
        temp.append((n1.length()-i-1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

        res = addThis(res, temp);
    }

    while(res[0] == '0' && res.length()!=1) // erase leading zeros
        res.erase(0,1);

    return res;
}

// End of Helper functions

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {

    string number = to_string(n);
    for(int i = n-1; i > 0; i--){
        number = multiplyThis(number, to_string(i));
    }
    cout << number;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}

