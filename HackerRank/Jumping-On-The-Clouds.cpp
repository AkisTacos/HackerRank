// Aki Saito
// HackerRank - Easy
// Jumping on the Clouds
// August 9, 2018
// Language: C++
// 
/* Description:

Emma is playing a new mobile game that starts with consecutively numbered clouds. 
Some of the clouds are thunderheads and others are cumulus. 
She can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus 1 or 2. 
She must avoid the thunderheads. 
Determine the minimum number of jumps it will take Emma to jump from her starting postion to the last cloud. 
It is always possible to win the game.

For each game, Emma will get an array of clouds numbered 0 if they are safe or 1 if they must be avoided. 
For example, c = [0, 1, 0, 0, 0, 1, 0] indexed from 0...6. 
The number on each cloud is its index in the list so she must avoid the clouds at indexes 1 and 5. 
She could follow the following two paths: 0 -> 2 -> 4 -> 6 or 0 -> 2 -> 3 -> 4 -> 6. 
The first path takes 3 jumps while the second takes 4.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Helper Function
int test_next_cloud(int current, int jump, vector<int>c){
    if(current + jump > c.size() - 1)
        return 0;
    
    if(c[current+jump] == 1)
        return 0;         
    else
        return 1; 

}

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int result = 0;
    int cloudsLeft = c.size()-1;
    int current = 0;
    vector<int> arr;
    while(cloudsLeft){
        if(test_next_cloud(current, 2, c)){
            cloudsLeft -= 2;
            current += 2;
        }   
        else {
            cloudsLeft -= 1;
            current += 1;
        }  
        result += 1;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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

