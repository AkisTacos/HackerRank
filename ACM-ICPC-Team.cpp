// Aki Saito
// HackerRank - Easy
// ACM ICPC Team
// August 17, 2018
// Language: C++
// 
/* Description:

	There are a number of people who will be attending ACM-ICPC World Finals. 
	Each of them may be well versed in a number of topics. 
	Given a list of topics known by each attendee, you must determine the maximum number of topics a 2-person team can know. 
	Also find out how many ways a team can be formed to know that many topics. 
	Lists will be in the form of bit strings, where each string represents an attendee and each position in that string 
	represents a field of knowledge, 1 if its a known field or 0 if not.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) {
    vector<int> result;
    unsigned int size = topic.size();
    unsigned int numberOfTopics = topic[0].length();
    unsigned int max = 0, topicKnown = 0, candidateResult = 0;
    unsigned int position = 1;
    // size = 4
    // number of topics = 5
    
    for(unsigned int currentPosVec = 0; currentPosVec < size; currentPosVec++){
        for(unsigned int nextPosVec = 1; nextPosVec < size; nextPosVec++){
            if(currentPosVec == nextPosVec || currentPosVec > nextPosVec)
                continue;
            for(unsigned int pos = 0; pos < topic[currentPosVec].size(); pos++){
                if(topic[currentPosVec][pos] == '1')
                    topicKnown += 1;
                else
                    if(topic[nextPosVec][pos] == '1')
                        topicKnown += 1;
            }

            if(topicKnown > max){
                max = topicKnown;
                candidateResult = 1;
            }
            else if(topicKnown == max)
                candidateResult += 1;
            topicKnown = 0;
        }
    }
    result.push_back(max);
    result.push_back(candidateResult);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

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

