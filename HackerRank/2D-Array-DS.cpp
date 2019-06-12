// Aki Saito
// HackerRank - Easy
// 2D Array - DS
// November 28, 2018
// Language: C++
// 
/* Description:
	Given a 6x6 2D Array, arr:
  1 1 1 0 0 0
  0 1 0 0 0 0 
  1 1 1 0 0 0 
  0 0 0 0 0 0 
  0 0 0 0 0 0
  0 0 0 0 0 0
  
  We define an hourglass in A to be a subset of values with indices falling in this pattern in arr's graphical representation:
  a b c
    d 
  e f g
  
  There are 16 hour glasses in arr, and an hourglass sum is the sum of an hourglass' values. 
  Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum.
  
  Function Description:
  Complete the function hourglassSum in the editor below. It should return an integer, the maximum hourglass sum in he array.
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int result = -63;
    int sum = 0;

    for(int row = 0; row < 4; row++)
        for(int col = 0; col < 4; col++){
            sum = arr[row][col]
            + arr[row][col+1]
            + arr[row][col+2]
            + arr[row+1][col+1]
            + arr[row+2][col]
            + arr[row+2][col+1]
            +arr[row+2][col+2]; 
            if(sum > result)
                result = sum;
        }            

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
