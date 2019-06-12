// Aki Saito
// HackerRank - Easy
// Practice>Interview Preparation Kit>Greedy Algorithms
// Lucky Balance
// March 16, 2019
// Language: C++
// 
/* Description:
	Lena is preparing for an important coding competition that is 
	preceded by a number of sequential preliminary contests. 
	She believes in "saving luck", and wants to check her theory.
	Each contest is described by two integers, L[i] and T[i]:

	L[i] is the amount of luck associated with a contest.
	If Lena wins the contest, her luck balance will decrease by L[i];
	if she loses it, her luck balance will increase by L[i].

	T[i] denotes the contest's importance rating. 
	It's equal to 1 if the contest is important, and it's equal 
	to 0 if it's unimportant.

	If Lena loses no more than k important contests, 
	what is the maximum amount of luck she can have 
	after competing in all the preliminary contests? 
	This value may be negative.
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    // First line contains n, number of contests
    // and k, number of contests Lena can lose
    int n, k;
    cin >> n;
    cin >> k;

    // Create our database
    multimap<int, int, greater<int>> contests;
    int luck, type, i;

    for(i = 0; i < n; i++){
        cin >> luck;
        cin >> type;
        contests.insert(pair<int, int>(luck, type));
    }

    // Create an iterator for multimap and calculate results
    int result = 0;

    for(multimap<int, int>::iterator it=contests.begin(); it!=contests.end(); ++it){
        if(it->second == 0)
            result += it->first;
        else
            if(k-- > 0)
                result += it->first;
            else
                result -= it->first;      
    }

    cout << result;
}


