// Aki Saito
// HackerRank Contest - Easy
// Is Palindrome
// November 28, 2018
// Language: C++
// 
/* Description:
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

  Input Format
    A single line which contains the input string.
  Output Format
    A single line which contains YES or NO in uppercase.
  
  Sample Input:
      A man, a plan, a canal: Panama

  Sample Output
      YES

  Explanation
  Have you consider that the string might be empty? This is a good question to ask during an interview.
  For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string input;
    getline(cin, input);
    if(input.empty())
        cout << "YES";
    
    // Lowercase it
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    // Erase punctuations and spaces
    for (int i = 0, len = input.size(); i < len; i++){
        if (ispunct(input[i])){
            input.erase(i--, 1);
            len = input.size();
        }
        if (isspace(input[i])){
            input.erase(i--, 1);
            len = input.size();
        }
    }
    
    // Check if palindrome
    int last = input.length()-1;
    for(int i = 0; i < input.length()/2; i++){
        if(input[i] != input[last-i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
