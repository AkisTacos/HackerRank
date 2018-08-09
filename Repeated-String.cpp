// Aki Saito
// HackerRank - Easy
// Repeated String
// August 9, 2018
// Language: C++
// 
/* Description:

Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.

Given an integer, n, find and print the number of letter a's in the first n letters of Lilah's infinite string.

For example, if the string s = 'abcac' and n = 10, the substring we consider is abcacabcac, the first 10 characters of her infinite string. 
There are 4 occurrences of a in the substring.

*/

#include <bits/stdc++.h>

using namespace std;

// Helper Function
int final_check(int check, string s){
    int result = 0;
    for(char& c : s){
        if(check == 0)
            break;
        else
            if(c == 'a')
                result += 1;
        check -= 1;
    }
    return result;
}

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long result = 0;
    long num_a = 0;
    for(char& c : s)
        if( c == 'a')
            num_a += 1;
    
    if(num_a == 0)
        return result;
    
    if(n/s.length() == 0)
        result += final_check(n, s);
    else
        result = (num_a * (n/(s.length()))) + final_check((n % s.length()), s);
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

