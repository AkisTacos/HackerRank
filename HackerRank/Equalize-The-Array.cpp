// Aki Saito
// HackerRank - Easy
// Equalize the Array
// August 9, 2018
// Language: C++
// 
/* Description:

Karl has an array of integers. 
He wants to reduce the array until all remaining elements are equal. 
Determine the fewest number of elements to delete to reach his goal.

For example, if his array is arr = [1, 2, 2, 3], we see that he can delete the 2 elements 1 and 3 leaving arr = [2, 2]. 
He could also delete both twos and either the 1 or the 2\3, but that would take 3 deletions. 
The minimum number of deletions is 2.

*/

#include <bits/stdc++.h>
#define MAX_ALLOWED 100
using namespace std;

vector<string> split_string(string);

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
    int count[MAX_ALLOWED+1];
    int max = 0;
    
    for(int i = 0; i < sizeof(count)/sizeof(count[0]); i++)
        count[i] = 0;
    
    for(int num : arr)
        count[num] += 1;        
    
    for(int i = 0; i < sizeof(count)/sizeof(count[0]); i++)
        if(count[i] > max)
            max = count[i];

    return (arr.size() - max);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = equalizeArray(arr);

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

