// Aki Saito
// HackerRank - Medium
// Sherlock and the Valid String
// February 8, 2019
// Language: C++
// 
/* Description:
	Sherlock considers a string to be valid if all characters of the string appear the same number of times. 
  It is also valid if he can remove just 1 character at 1 index in the string, and the remaining chracters
  will occur the same number of time. Given a string s, determine if is valid. If so, return YES, 
  otherwise return NO.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    string result = "NO";
    map<char, int> letterBank;
    map<char, int>::iterator itr;

    for(int i = 0; i < s.length(); i++){
        letterBank[s[i]] += 1;
    }

    itr = letterBank.begin();
    int first = itr->second;
    int numOfChange = 0;
    for(itr = letterBank.begin(); itr != letterBank.end(); itr++){

        if(first != itr->second){
            cout << "Miss\n";
            numOfChange++;
            cout << "Num of change: " << numOfChange << endl;
        }
    }

    if((numOfChange == 1) || (numOfChange == 0)){
        return "YES";
    }
    

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
