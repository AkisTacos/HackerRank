// Aki Saito
// HackerRank - Easy
// Find Digits
// July 25, 2018
// Language: C++
// 
/* Description:

	You have a string of lowercase English alphabetic letters. 
	You can perform two types of operations on the string:
	
		1. Append a lowercase English alphabetic letter to the end of the string.
		2. Delete the last character in the string. 
		   Performing this operation on an empty string results in an empty string.
	
	Given an integer, k, and two strings, s and t, determine whether or not you can 
	convert s to by performing exactly k of the above operations on s. 
	If it's possible, print Yes. Otherwise, print No.
	
	For example, strings s = [a, b, c] and t = [d, e, f]. 
	Our number of moves, k = 6. 
	To convert s to t, we first delete all of the characters in 3 moves. 
	Next we add each of the characters of in order. 
	On the 6th move, you will have the matching string. 
	If there had been more moves available, they could have been eliminated by performing multiple deletions on an empty string. 
	If there were fewer than 6 moves, we would not have succeeded in creating the new string.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    // s is our start string
    // t is our desired string
    // k is the number of operations
    int i;
    int sumString = s.length() + t.length();
    int calc;
    
    string result;
    // Case where both s and t are same
    if(s.compare(t) == 0){
        // if k is even or s.size + t.size is >= k then it's always YES
        if(k % 2 == 0 || sumString <= k )
            result = "Yes";
        else
            result =  "No";
    } else {
        // s != t
        if(sumString <= k)
            result = "Yes";
        else {
            i = 0;
            while(s[i] == t[i]){
                i++;
            }
            calc = k - (sumString - (2*i));
            if(calc < 0)
                result = "No";
            else{
                if(calc % 2 == 0)
                    result = "Yes";
                else
                    result = "No";
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}


