// Aki Saito
// HackerRank - Easy
// Sequence Equation
// July 25, 2018
// Language: C++
// 
/* Description:

	You are given a sequence of n integers, p(1), p(2), ..., p(n). 
	Each element in the sequence is distinct and satisfies 1 <= p(x) <= n. 
	For each x where 1 <= x <= n, find any integer y such that p(p(y)) ~= x 
	and print the value of y on a new line.

	For example, assume you have the sequence p = [5, 2, 1, 3, 4]. 
	For each value of x between 1 and 5 we analyze as follows:
	1. x = 1 ~= p[3], p[4] = 3, so p[p[4]] = 1 
	2. x = 2 ~= p[2], p[2] = 2, so p[p[2]] = 2
	3. x = 3 ~= p[4], p[5] = 4, so p[p[5]] = 3
	4. x = 4 ~= p[5], p[1] = 5, so p[p[1]] = 4
	5. x = 5 ~= p[1], p[3] = 1, so p[p[3]] = 5

	We find the values [4, 2, 5, 1, 3] for y. 

*/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    
    vector<int> result;
    int position_x = 1;
    int position_y = 1;

    // From 1 to n
    for(int x = 1; x <= p.size(); x++){
        for(auto num : p){
            if(x != num)
                position_x += 1;
            else
                break;
        }
        for(auto num : p){
            if(position_x != num)
                position_y += 1;
            else
                break;
        }
        result.push_back(position_y);
        position_x = 1;
        position_y = 1;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

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


