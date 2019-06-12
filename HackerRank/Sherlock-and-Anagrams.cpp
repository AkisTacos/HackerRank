// Aki Saito
// HackerRank - Medium
// Sherlock and Anagrams
// February 8, 2019
// Language: C++
// 
/* Description:
	Two strings are anagrams of each other if the letters of one string can be rearranged 
  to form the other string. Given a string, find the number of pairs of substrings of
  the string that are anagrams of each other.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int result = 0;
    int subStringLen = 1;

    for(int i = 1; i < s.length(); i++){
        vector<string> substring(0);
        // Save all possible substrings from string
        for(int stringPosition = 0; stringPosition < s.length(); stringPosition++)
            substring.push_back(s.substr(stringPosition, subStringLen));
        
        // Sort all substrings
        for(int strPos = 0; strPos < substring.size(); strPos++)
            sort(substring[strPos].begin(), substring[strPos].end());

        // Increment result for every substring that matches
        for(int first = 0; first < substring.size(); first++)
            for(int second = first + 1; second < substring.size(); second++)
                if(substring[first] == substring[second])
                    result++;
        // Find result of next substring length
        subStringLen++;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
