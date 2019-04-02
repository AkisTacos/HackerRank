// Aki Saito
// HackerRank - Easy
// For Loop
// April 1, 2019
// Language: C++
// 
/* Description:
	An array is a series of elements of the same type placed in contiguous memory locations
  that can be individually referenced by adding an index to a unique indentifier.
  
  Declaration:
    int arr[10]; // Declares an array named arr of size 10
    
  Accessing elements of an array:
    Indexing in array starts from 0. So the first element is stored at arr[0], the 
    second element at arr[1]...arr[9]
    
  You'll be given an array of N integers and you have to print the integers in the 
  reverse order.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /*
    -------The for-loop way-------
    int size, i;
    cin >> size;
    int arr[size];
    for(i = 0; i < size; i++)
        cin >> arr[i];

    for(i = size-1; i >= 0; i--)
        cout << arr[i] << ' ';
    */

    // The vector way
    vector<int> numList;
    int size, i, pushNum;
    cin >> size;
    for(i = 0; i < size; i++){
        cin >> pushNum;
        numList.push_back(pushNum); 
    }
    reverse(numList.begin(), numList.end());

    for(auto numbers : numList)
        cout << numbers << ' ';

    return 0;
}
