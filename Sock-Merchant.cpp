// Aki Saito
// HackerRank - Easy
// Sock Merchant
// July 18, 2018
// Language: C++
// 
/* Description:
	John works at a clothing store. 
	He has a large pile of socks that he must pair them by color for sale.
	
	You will be given an array of integers representing the color of each sock. 
	Determine how many pairs of socks with matching colors there are.

	John works at a clothing store and he's going through a pile of socks to find the number of matching pairs. 
	More specifically, he has a pile of n loose socks where each sock i is labeled with an integer, ci, denoting its color. 
	He wants to sell as many socks as possible, but his customers will only buy them in matching pairs. 
	Two socks, i and j, are a single matching pair if they have the same color (ci = cj).
	Given n and the color of each sock, how many pairs of socks can John sell?

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    // n is the number of socks
    // ar is the array of color socks
    
    // return variable
    int result = 0;
    
    // Dictionary to keep track of how many colors
    map<int, int> sockPile;
    // Go through given array and add 
    for(int i = 0; i < n; i++){
        if (sockPile.find(ar[i]) == sockPile.end()){
            sockPile[ar[i]] = 1;
        } else {
            sockPile[ar[i]] += 1;
        }
    }
    
    // Go through each sock pile and check if 2 can divide
    // if so then that is a pair of sock pile
    for(map<int, int>::iterator it = sockPile.begin(); it != sockPile.end(); ++it) {
        if( ((it->second / 2) > 0) ) {
            result += it->second/2;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

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



