// Aki Saito
// HackerRank - Easy
// Divisible Sum Pairs
// July 18, 2018
// Language: C++
// 
/* Description:
    You are given an array of n integers, a0, a1,..., an-1 and a positive integer, k.
    Find and print the number of (i, j) pairs where i < j and ai + aj is divisible by k.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
   
	// n is number of elements in array
	// k is our to be divisible by
	// ar is our given array with n elements 

	// Helper Variable
	int counter = 0;
	int result = 0;


	// Go through each element in array
	while(counter < n-1) {
		// Go through every proceeding elements
		for(int i = counter; i < n; i++) {
			// Check if current element + next element(s) is divisible by k
			if(i == counter){
				continue;
			}
			if(((ar[counter] + ar[i]) % k) == 0){
				result++;
            
			}
		}
		counter++;
	}

	return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

