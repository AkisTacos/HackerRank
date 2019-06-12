// Aki Saito
// HackerRank - Easy
// Migratory Birds
// July 18, 2018
// Language: C++
// 
/* Description:
	You have been asked to help study the population of birds migrating across the continent. 
	Each type of bird you are interested in will be identified by an integer value. 
	Each time a particular kind of bird is spotted, its id number will be added to your array of sightings. 
	You would like to be able to find out which type of bird is most common given a list of sightings. Your task is to print the type number of that bird and if two or more types of birds are equally common, choose the type with the smallest ID number.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> ar) {
    
    map<string, int> birdMap;
    
    // Make 1-5 Types
    string type = "Type ";
    for(int i = 1; i < 6; i++) {
        type = "Type " + to_string(i);
        birdMap[type] = 0;
    }
    
    
    // Return Variable and counter for max
    int max = 0;
    int result = 0;
    
    // Keep track of each bird type sightings
    for(int i = 0; i < ar.size(); i++){
        switch(ar[i]){
            case 1: birdMap["Type 1"] += 1;
                    if(birdMap["Type 1"] > max){
                        max = birdMap["Type 1"];
                        result = 1;
                    }
                    break;
            case 2: birdMap["Type 2"] += 1;
                    if(birdMap["Type 2"] > max){
                        max = birdMap["Type 2"];
                        result = 2;
                    }
                    break;
            case 3: birdMap["Type 3"] += 1;
                    if(birdMap["Type 3"] > max){
                        max = birdMap["Type 3"];
                        result = 3;
                    }
                    break;
            case 4: birdMap["Type 4"] += 1;
                    if(birdMap["Type 4"] > max){
                        max = birdMap["Type 4"];
                        result = 4;
                    }
                    break;
            case 5: birdMap["Type 5"] += 1;
                    if(birdMap["Type 5"] > max){
                        max = birdMap["Type 5"];
                        result = 5;
                    }
                    break;
        }
    }
    
    // Check if there multiple max(s) and set result
    for(int i = 1; i < 6; i++){
        if(birdMap["Type 1"] == max) {
            if(result > 1)
                result = 1;
        }
        else if (birdMap["Type 2"] == max) {
            if (result > 2) {
                result = 2;
            }   
        }
        else if (birdMap["Type 3"] == max) {
            if(result > 3) {
                result = 3;
            }
        }
        else if (birdMap["Type 4"] == max) {
            if(result > 4)
                result = 4;
        }
    }
    
    cout << result;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int ar_count;
    cin >> ar_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = migratoryBirds(ar);

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

