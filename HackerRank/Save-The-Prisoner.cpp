// Aki Saito
// HackerRank - Easy
// Save The Prisoner
// July 23, 2018
// Language: C++
// 
/* Description:

	A jail has a number of prisoners and a number of treats to pass out to them. 
	Their jailer decides the fairest way to divide the treats is to seat the prisoners 
	around a circular table in sequentially numbered chairs. A chair number will be drawn from a hat.
	Beginning with the prisoner in that chair, one candy will be handed to each prisoner 
	sequentially around the table until all have been distributed.

	The jailer is playing a little joke, though. The last piece of candy looks like all the others, 
	but it tastes awful. Determine the chair number occupied by the prisoner who will receive that candy.

	For example, there are 4 prisoners and 6 pieces of candy. 
	The prisoners arrange themselves in seats numbered 1 to 4. 
	Let's suppose two is drawn from the hat. 
	Prisoners receive candy at positions 2, 3, 4, 1, 2, 3. 
	The prisoner to be warned sits in chair number 3.

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {
    // n is the number of prisoners
    // m is the number of sweets
    // s is the chair number to start passing treats at
    
    int prisoners = n;
    int sweets = m;
    int startChair = s;
    int sweetsLeft;
    int savePrisoner = 0;
    // Base case: if there's only one prisoner
    if(prisoners == 1)
        return 1;
    
    // We have 3 cases:
    
    // 1) We have exact number of sweets for every prisoner
        // Then we want save the prisoner behind where it started
    if(prisoners == sweets)
        if (startChair == 1)
            return prisoners; 
        else 
            return startChair - 1;
    // 2) We have more sweets than prisoners:
    else if(prisoners < sweets){
        // 2-1) We can evenly distribute the sweets
        if( (sweets % prisoners) == 0 )
            // Then we know again the prisoner before start with will get it
            if ( startChair == 1)
                savePrisoner = prisoners;
            else 
                savePrisoner = startChair - 1;
                
        // 2-2) We cannot evenly distribute
        else {
            // We find the remainder and add it to our start
            sweetsLeft = sweets % prisoners;
            savePrisoner = startChair + sweetsLeft-1;
            // Check if it went over
            while( savePrisoner > prisoners ){
                // Return the difference
                savePrisoner -= prisoners;
            } 
        }
    } // End of case 2     
    // 3) We have less sweets than prisoners
    else {
        // We give the sweets out
        savePrisoner = startChair + sweets - 1;
        // Check if it went over
        while(savePrisoner > prisoners){
            savePrisoner -= prisoners;
        }
    }
    return savePrisoner;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nms_temp;
        getline(cin, nms_temp);

        vector<string> nms = split_string(nms_temp);

        int n = stoi(nms[0]);

        int m = stoi(nms[1]);

        int s = stoi(nms[2]);

        int result = saveThePrisoner(n, m, s);

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

