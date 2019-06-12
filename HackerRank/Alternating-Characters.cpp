// Aki Saito
// HackerRank - Easy
// Alternating Characters
// February 8, 2019
// Language: C++
// 
/* Description:
	You are given a string containing characters A and B only.
  Your task is to change it into a string such that there are no matching ajdacent characters.
  To do this, you are allowed to delete zero or more characters in the string.
  
  Your task is to find the minimum number of required deletions.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int result = 0;
    char temp = s[0];
    for(int i = 1; i < s.length(); i++){
        if(temp == s[i])
            result += 1;
        temp = s[i];
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
