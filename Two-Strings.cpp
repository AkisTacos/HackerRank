// Aki Saito
// HackerRank - Easy
// Two Strings
// February 8, 2019
// Language: C++
// 
/* Description:
	Find the minimum cost of copying string s.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    int found = -1;
    for(int i = 0; i < s1.length(); i++){
        found = s2.find(s1[i]);
        if(found >= 0){
            return "YES";
        }
    }
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
