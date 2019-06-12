// Aki Saito
// HackerRank - Easy
// Angry Professor
// July 23, 2018
// Language: C++
// 
/* Description:

	A Discrete Mathematics professor has a class of students. 
	Frustrated with their lack of discipline, he decides to cancel class if 
	fewer than some number of students are present when class starts. 
	Arrival times go from on time (arrivalTime <= 0) to arrived late (arrivalTime > 0).
	
	Given the arrival time of each student and a threshhold number of attendees, 
	determine if the class is canceled.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the angryProfessor function below.
string angryProfessor(int k, vector<int> a) {
    // k = cancellation threshold
    // a = array of arrival time
    
    int attendance = 0;
    // check each time the students arrived
    for(auto time : a){
        if(time <= 0)
            attendance += 1;
    }
    
    // check if time is below or above threshold
    if(attendance >= k)
        return "NO";
    else
        return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string result = angryProfessor(k, a);

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

