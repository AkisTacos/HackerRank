// Aki Saito
// HackerRank - Easy
// Variable Sized Arrays
// April 1, 2019
// Language: C++
// 
/* Description:
	Consider an n-element array, a, where each index i, in the array contains a 
  reference to an array of k_i integers (where the avlue of k_i varies from
  array to array). 
  
  Given a, you must answer q queries. Each query is in the format i j, where i 
  denotes an index in array a and j denotes an index in the array located at
  a[i]. For each query, find and print the value of element j in the array
  at location a[i] on a new line.
*/
  
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    // For simplicity and clarity, we will assume number of array -> number of
    // rows and number of query -> number of questions
    
    int numOfRows, numOfQuestion, size, number, i, j;
    vector<vector<int>> rowVector;
    vector<int> colVector;
    cin >> numOfRows >> numOfQuestion;
    for(i = 0; i < numOfRows; i++){
        cin >> size;
       for(j = 0; j < size; j++){
            cin >> number;
            colVector.push_back(number);
        } 
        rowVector.push_back(colVector);
        colVector.clear();
    }
    // Print
    int row, col;
    for(i = 0; i < numOfQuestion; i++){
        cin >> row >> col;
        cout << rowVector[row][col] << endl;
    }
    return 0;
}



