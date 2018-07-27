// Aki Saito
// HackerRank - Easy
// Sherlock and Squares
// July 26, 2018
// Language: C++
// 
/* Description:

	Watson likes to challenge Sherlock's math ability. 
	He will provide a starting and ending value describing a range of integers. 
	Sherlock must determine the number of square integers within that range, 
	inclusive of the endpoints.

	Note: A square integer is an integer which is the square of an integer, e.g. 1, 4, 9, 16, 25.
	
	For example, the range is a = 24 and b = 49, inclusive. 
	There are three square integers in the range: 25, 36 and 49.

	Function Description
	Complete the squares function in the editor below. 
	It should return an integer representing the number of square integers in the inclusive range from a to b.
	squares has the following parameter(s):
	
	a: an integer, the lower range boundary
	b: an integer, the uppere range boundary

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the squares function below.
int squares(int a, int b) {
    int result = 0;
    int root, perfSquare;
    for(int i = a; i <= b; i++){
        root = int(sqrt(i));
        if( (root * root) == i){
            perfSquare = i;
            result += 1;
            break;
        }
    }
    bool notDone = true;
    int nextSquare;
    while(notDone){
        nextSquare = pow( (sqrt(perfSquare) + 1), 2);
        if(nextSquare <= b){
            result += 1;
            perfSquare = nextSquare;
        }
        else {
            notDone = false;
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string ab_temp;
        getline(cin, ab_temp);

        vector<string> ab = split_string(ab_temp);

        int a = stoi(ab[0]);

        int b = stoi(ab[1]);

        int result = squares(a, b);

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


