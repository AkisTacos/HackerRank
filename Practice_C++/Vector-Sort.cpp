// Aki Saito
// HackerRank - Easy
// Vector-Sort
// April 10, 2019
// Language: C++
// 
/* Description:
    
    You are given N integers. Sort the N integers and print the sorted order.
    Store the N integers in a vector. Vectors are sequence containers representing
    arrays that can change in size.

    Declaration:
		vector<int>v; (creates an empty vector of integers)

	Size:
		int size=v.size();

	Pushing an integer into a vector:
		v.push_back(x);(where x is an integer.The size increases by 1 after this.)

	Popping the last element from the vector:
		v.pop_back(); (After this the size decreases by 1)

	Sorting a vector:
		sort(v.begin(),v.end()); (Will sort all the elements in the vector)

	
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    vector<int> numVec;
    int size, i, number;
    cin >> size;
    for(i = 0; i < size; i++){
    	cin >> number;
    	numVec.push_back(number);
    }
    sort(numVec.begin(), numVec.end());
    cout << numVec;

    return 0;
}