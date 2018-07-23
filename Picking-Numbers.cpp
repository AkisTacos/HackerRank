// Aki Saito
// HackerRank - Easy
// Picking Numbers
// July 21, 2018
// Language: C++
// 
/* Description:

	Given an array of integers, find and print the maximum number of integers 
	you can select from the array such that the absolute difference between any 
	two of the chosen integers is less than or equal to 1. 
	
	For example, if your array is a = [1, 1, 2, 2, 4, 4, 5, 5, 5], you can 
	create two subarrays meeting the criterion: [1, 1, 2, 2] and [4, 4, 5, 5, 5]. 
	The maximum length subarray has 5 elements.


*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pickingNumbers function below.
int pickingNumbers(vector<int> a) {
    // a = given array of integers
    
    // Helper Variables
    int max = 0;
    int high = 0;
    
    // Find highest value in array a
    for(auto x : a){
        if(high < x){
            high = x;
        }
    }

    // Make new array with high*high to have enough space
    int array[high*high] = {0};
    
    // Go through array a again
    for(int i = 0; i < a.size(); i++){
        // Keep track of how many of same i'th value there are
        array[a[i]] += 1;
    }
    
    // Check which two elments can form the highest subgroup value
    for(int i = 0; i < a.size()-1; i++){
        if(max < array[i] + array[i+1])
            max = array[i] + array[i+1];
    }
    
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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


