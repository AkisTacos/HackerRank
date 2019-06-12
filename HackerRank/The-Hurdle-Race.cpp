// Aki Saito
// HackerRank - Easy
// The Hurdle Race
// July 23, 2018
// Language: C++
// 
/* Description:

	Dan is playing a video game in which his character competes in a hurdle race. 
	Hurdles are of varying heights, and Dan has a maximum height he can jump. 
	There is a magic potion he can take that will increase his maximum height 
	by 1 unit for each dose. 
	How many doses of the potion must he take to be able to jump all of the hurdles.

	Given an array of hurdle heights height, and an initial maximum height Dan 
	can jump, k, determine the minimum number of doses Dan must take to be able to 
	clear all the hurdles in the race.

	For example, if height = [1, 2, 3, 3, 2] and Dan can jump 1 unit high naturally, 
	he must take 3 - 1 = 2 doses of potion to be able to jump all of the hurdles.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the hurdleRace function below.
int hurdleRace(int k, vector<int> height) {
    // k is the max height he can jump
    
    // First get max height in the hurdles
    int max = 0;
    for(auto h : height){
        if(max < h)
            max = h;
    }
    
    // Now we check how many doses he will need
    return (((max - k) > 0) ? (max - k) : (0));
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string height_temp_temp;
    getline(cin, height_temp_temp);

    vector<string> height_temp = split_string(height_temp_temp);

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        int height_item = stoi(height_temp[i]);

        height[i] = height_item;
    }

    int result = hurdleRace(k, height);

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

