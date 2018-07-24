// Aki Saito
// HackerRank - Easy
// Beautiful Days At The Movies
// July 23, 2018
// Language: C++
// 
/* Description:

	Lily likes to play games with integers. 
	She has created a new game where she determines the difference between a 
	number and its reverse. 
	For instance, given the number 12, its reverse is 21. Their difference is 9. 
	The number 120 reversed is 21, and their difference is 99.
	
	She decides to apply her game to decision making. 
	She will look at a numbered range of days and will only go to a movie on a beautiful day.
	
	Given a range of numbered days, [i...j] and a number k, determine the number of days in 
	the range that are beautiful. Beautiful numbers are defined as numbers where [i-reverse(i)] is 
	evenly divisible by l. If a day's value is a beautiful number, it is a beautiful day. 
	Print the number of beautiful days in the range.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int reverse(int number){
    // Reverse number
    int remainder = 0;
    int reverse = 0;
    while(number != 0){
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;
    }
    return reverse;
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    // i is the start date of movie watching
    // j is the end date of movie watching
    // k is our divisor
    
    int possibleNumber = 0;
    int beautyNumber = 0;
    // go from integer i to j
    for(int start = i; start <= j; start++){
        // for each integer we calculate beautiful or not
        possibleNumber = abs(start - reverse(start));
        if((possibleNumber % k) == 0)
             beautyNumber += 1;
    }
    return beautyNumber;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

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

