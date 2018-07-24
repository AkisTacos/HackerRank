// Aki Saito
// HackerRank - Easy
// Viral Advertising
// July 23, 2018
// Language: C++
// 
/* Description:

	HackerLand Enterprise is adopting a new viral advertising strategy. 
	When they launch a new product, they advertise it to exactly 5 people on social media.
	
	On the first day, half of those 5 people (i.e., floor(5/2) = 2) like the advertisement 
	and each shares it with of their friends. 
	At the beginning of the second day, floor(5/2) * 3 = 2 x 3 = 6 people receive the advertisement.
	
	Each day, floor(recipients/2) of the recipients like the advertisement and will share it 
	with 3 friends on the following day. Assuming nobody receives the advertisement twice, 
	determine how many people have liked the ad by the end of a given day, beginning with launch day as day 1.
	
	For example, assume you want to know how many have liked the ad by the end of the 5th day.

	Day Shared Liked Cumulative
	1      5     2       2
	2      6     3       5
	3      9     4       9
	4     12     6      15
	5     18     9      24

	The cumulative number of likes is 24.

*/

#include <bits/stdc++.h>

using namespace std;

int growthOfLikes(int daysLeft, int people, int likes){
    // Base case where no more days are left
    if(daysLeft == 0)
        return likes;
    // Calculate people
    people = (people/2) * 3;
    // Calculate likes according to people
    likes += people/2;
    return growthOfLikes(daysLeft-1, people, likes);
}

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    // n is the number of days
    int likes = 2;
    likes = growthOfLikes(n-1, 5, likes);
    return likes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

