// Aki Saito
// HackerRank - Easy
// Jumping On The Clouds: Revisited
// July 25, 2018
// Language: C++
// 
/* Description:

	Aerith is playing a cloud hopping game. 
	In this game, there are sequentially numbered clouds that can be thunderheads or cumulus clouds. 
	Her character must jump from cloud to cloud until it reaches the start again.
	
	To play, Aerith is given an array of clouds, c and an energy level e = 100. 
	She starts from c[0] and uses 1 unit of energy to make a jump of size k to cloud c[(i+k) % n]. 
	If Aerith lands on a thundercloud, c[i] = 1, her energy (E) decreases by 2 additional units. 
	The game ends when Aerith lands back on cloud 0.

	Given the values of n, k, and the configuration of the clouds as an array c, can you determine 
	the final value of e after the game ends?

	For example, give c = [0, 0, 1, 0] and k = 2, the indices of her path are 0 -> 2 -> 0. 
	Her energy level reduces by 1 for each jump to 98. 
	She landed on one thunderhead at an additional cost of 2 energy units. 
	Her final energy level is 96.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k) {
    // k is our jump distance
    // c is our given cloud array
    
    int energy = 100;
    int numberOfJumps = c.size() / k;
    int position = k;
    
    for(int i = 1; i <= numberOfJumps; i++){
        energy -= 1;
        if(position > c.size()-1)
            position -= c.size();
        if(c.at(position) == 1)
            energy -= 2;   
        position += k;
    }
    return energy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c, k);

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

