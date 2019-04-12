// Aki Saito
// HackerRank - Easy
// Lower Bound-STL
// April 10, 2019
// Language: C++
// 
/* Description:
    
    You are given N integers in sorted order. Also, you are given Q queries. 
    In each query, you will be given an integer and you have to tell whether 
    that integer is present in the array. If so, you have to tell at which index 
    it is present and if it is not present, you have to tell the index at which the 
    smallest integer that is just greater than the given number is present.
	
	The function optimizes the number of comparisons performed by comparing 
	non-consecutive elements of the sorted range, which is specially efficient 
	for random-access iterators.
	
	Use: 
		int someTargetNum;
		vector<int> myVec;
		vector<int>:: iterator lower;
		lower = lower_bound(myVec.begin(), myVec.end(), someTargetNum);
		if(*lower == someTargetNum)
			cout << "Found it at position " << lower - myVector.begin() + 1 << endl; 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, i, num;
    cin >> n;

    vector<int> numbers;
    for(i = 0; i < n; i++){
        cin >> num;
        numbers.push_back(num);
    }
    int q;
    vector<int>::iterator low, it;
    cin >> q;
    for(i = 0; i < q; i++){
        cin >> num;
        low = lower_bound(numbers.begin(), numbers.end(), num);
        if(*low == num)
            cout << "Yes " << low - numbers.begin() + 1 << endl; 
        else
            cout << "No " << low - numbers.begin() + 1 << endl;
    }

    return 0;
}

