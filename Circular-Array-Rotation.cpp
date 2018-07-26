// Aki Saito
// HackerRank - Easy
// Circular Array Rotation
// July 25, 2018
// Language: C++
// 
/* Description:

	John Watson knows of an operation called a right circular rotation on an array of integers. 
	One rotation operation moves the last array element to the first position and shifts all remaining elements right one. 
	To test Sherlock's abilities, Watson provides Sherlock with an array of integers. 
	Sherlock is to perform the rotation operation a number of times then determine the value of the element at a given position.
	
	For each array, perform a number of right circular rotations and return the value of the element at a given index.
	
	For example, array a = [3, 4, 5], number of rotations, k = 2 and indices to check, m = [1, 2]. 
	First we perform the two rotations: 
	[3, 4, 5] -> [5, 3, 4] ->[4. 5. 3]
	 
	Now return the values from the zero-based indices 1 and 2 as indicated in the m array. 
	a[1] = 5
	a[2] = 3 

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    // a = given array of integers to rotate
    // k = number of rotation
    // queries = indexes to report
    int pos;
    reverse(a.begin(), a.end());
    if (k == 1)
        rotate(a.begin(), a.begin()+1, a.end());
    else {
        k = k % a.size();
        if( k != 0)
            rotate(a.begin(), a.begin()+k, a.end());
    }
    reverse(a.begin(), a.end());

    vector<int> result;
    for(pos = 0; pos < queries.size(); pos++){
        result.push_back(a[queries[pos]]);            
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkq_temp;
    getline(cin, nkq_temp);

    vector<string> nkq = split_string(nkq_temp);

    int n = stoi(nkq[0]);

    int k = stoi(nkq[1]);

    int q = stoi(nkq[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = circularArrayRotation(a, k, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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




