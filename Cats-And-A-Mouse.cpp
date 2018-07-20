// Aki Saito
// HackerRank - Easy
// Cats And a Mouse
// July 19, 2018
// Language: C++
// 
/* Description:

	Two cats and a mouse are at various positions on a line. 
	You will be given their starting positions. 
	Your task is to determine which cat will reach the mouse first, 
	assuming the mouse doesn't move and the cats travel at equal speed. 
	If the cats arrive at the same time, the mouse will be allowed to move 
	and it will escape while they fight.
	
	You are given  queries in the form of x, y, and z representing the 
	respective positions for cats A and B, and for mouse C. 
	Complete the function catAndMouse to return the appropriate answer to each query, 
	which will be printed on a new line.
	
	If cat A catches the mouse first, print Cat A.
	If cat B catches the mouse first, print Cat B.
	If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
    // x is position of cat A
    // y is position of cat B
    // z is position of mouse C
    
    int result = 0;
    int catAToMouse = abs(z - x);
    int catBToMouse = abs(z - y);
    
    // Check if distance is same, cat A is greater or not return appropriately 
    if ( catAToMouse == catBToMouse )
        return "Mouse C";
    else {
        if ( catAToMouse > catBToMouse )
            return "Cat B";
        else
            return "Cat A";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xyz_temp;
        getline(cin, xyz_temp);

        vector<string> xyz = split_string(xyz_temp);

        int x = stoi(xyz[0]);

        int y = stoi(xyz[1]);

        int z = stoi(xyz[2]);

        string result = catAndMouse(x, y, z);

        fout << result << "\n";
    }

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


