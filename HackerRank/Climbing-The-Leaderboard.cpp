// Aki Saito
// HackerRank - Medium
// Climbing the Leaderboard
// July 23, 2018
// Language: C++
// 
/* Description:

	Alice is playing an arcade game and wants to climb to the top of the leaderboard. 
	Can you help her track her ranking as she plays? 
	The game uses Dense Ranking, so its leaderboard works like this:
	
	The player with the highest score is ranked number 1 on the leaderboard.
	Players who have equal scores receive the same ranking number, 
	and the next player(s) receive the immediately following ranking number.
	
	We want to determine Alice's rank as she progresses up the leaderboard. 
	For example, the four players on the leaderboard have high scores of 100, 90, 90, and 80. 
	Those players will have ranks 1, 2, 2, and 3, respectively. 
	If Alice's scores are 70, 80 and 105, her rankings after each game are 4, 3 and 1.
	You are given an array, scores, of monotonically decreasing leaderboard scores, 
	and another array, alice, of Alice's scores for the game. 
	You must print m integers. The jth integer should indicate the current rank of 
	alice after her jth game.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    // scores has leaderboard scores in decending order
    // alice has scores in acending order
    
    // Result for alice's rankings
    vector<int> result;
    int positionStart = 1;
    bool notDone = true;
    int posEnd = scores.size() - 1;
    
    // First make a rank array that will hold rank positions in leaderboard
    vector<int> rank(scores.size());
    for(int i = 0; i < scores.size(); i++){
        rank[i] = positionStart;
        if(scores[i] != scores[i+1])
            positionStart += 1;
    }
    
    // For every score alice got check for rank
    for(auto aliceScore : alice){
        // From bottom rank we make our way up until we find our spot for score
        while(posEnd != -1 && aliceScore > scores[posEnd]){
            posEnd -= 1;
        }
        // If alice's score and position we stopped are same then we return rank
        if(scores[posEnd] == aliceScore)
            result.push_back(rank[posEnd]);
        // If alice's score is greater than we beat that score's rank by 1
        else if(scores[posEnd] > aliceScore)
            result.push_back(rank[posEnd] + 1);
        else
        // Means alice's score beat all
            result.push_back(1);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

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

