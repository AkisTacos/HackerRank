// Aki Saito
// HackerRank - Easy
// Practice>Interview Preparation Kit>Greedy Algorithms
// Minimum Absolute Difference in an Array
// March 13, 2019
// Language: C++
// 
/* Description:
	Consider an array of integers, arr = [arr[0], arr[1], ..., arr[n-1]].
	We define the absolute difference between two elements, a[i] and a[j] (where i != j),
	to be the absolute value of a[i] - a[j].

	Given an array of integers, find and print the minimum absolute difference between
	any two elements in the array. For example, given the array arr = [-2, 2, 4] we can
	create 3 pairs of numbers: 
	[-2, 2], [-2, 4] and [2, 4].
	The absolute differences for these pairs are |(-2), -2| = 4, |(-2) - 4| = 6 
	and |2 - 4| = 2.

	The minimum absolute difference is 2.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	// We will have 2 inputs. 

	int n; // 1st line input, size of arr
	cin >> n; 

	int arr[n]; // 2nd line input, integers arr[i]
	int i;
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
	//Sort array, now the lowest two consecutive absolute difference is minimal
	sort(arr, arr+n);

	int j, min;
	int absMin = abs(arr[0] - arr[1]);
	for(i = 0; i < (n-1); i++){
		min = abs(arr[i] - arr[i+1]);
		if(min < absMin)
			absMin = min;
	}
	cout << absMin;

	return 0;
}