// Aki Saito
// HackerRank - Easy
// Counting Valley
// July 18, 2018
// Language: C++
// 
/* Description:

	Gary is an avid hiker. He tracks his hikes meticulously, paying close attention to small details like topography. 
	During his last hike, he took exactly n steps. For every step he took, he noted if it was an uphill, U, or a downhill, D step.
	Gary's hikes start and end at sea level and each step up or down represents a 1 unit change in altitude. 
	We define the following terms:
	
		A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level 
		and ending with a step down to sea level.
		A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level 
		and ending with a step up to sea level.
	
	Given Gary's sequence of up and down steps during his last hike, find and print the number of valleys he walked through.
	For example, if Gary's path is s = [DDUUUUDD], he first enters a valley 2 units deep. 
	Then he climbs out an up onto a mountain 2 units high. Finally, he returns to sea level and ends his hike.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    // U = up
    // D = down
    // n = number of U or D
    // s = holds all U and/or D
    
    int upCount, downCount = 0;
    int position = 0;
    int counter = 0;
    int valley = 0;
    
    if(s.at(0) == 'D'){
        counter += 1;
        position -= 1;
        valley = 1;
    } else {
        position += 1;
    }
    
    for(int i = 1; i < n; i++) {
        if(s.at(i) == 'U') {
            position += 1;
            if(position >= 0)
                valley = 0;

        } else {
            position -= 1;
            if ((position < 0) && (valley == 0)) {
                counter += 1;
                valley = 1;
            }
        }
    }
    
    return counter;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

