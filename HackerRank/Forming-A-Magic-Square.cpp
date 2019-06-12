// Aki Saito
// HackerRank - Medium
// Forming a Magic Square
// July 19, 2018
// Language: C++
// 
/* Description:

	We define a magic square to be an n x n matrix of distinct positive integers 
	from 1 to n^2 where the sum of any row, column, or diagonal of length n is 
	always equal to the same number: the magic constant.
	
	You will be given a 3 x 3 matrix s of integers in the inclusive range [1, 9]. 
	We can convert any digit a to any other digit b in the range [1, 9] at cost of |a - b|. 
	Given s, convert it into a magic square at minimal cost. Print this cost on a new line.

	Note: The resulting magic square must contain distinct integers in the inclusive range [1, 9].

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    // s is the 3 x 3 matrix we need to solve
    
    int cost = 0;
    // First get our cost for the first way of making the box
    int firstSquare[3][3] = { {8, 1, 6}, {3, 5, 7}, {4, 9, 2} };
    
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            // For each row and col calculate absolute difference 
            // of each value in [row][col] with the 8 correct 
            // ways to make magic box
            cost += abs(firstSquare[row][col] - s[row][col]);
        }
    }

    // Now we check for the other ways...
    // There are 7 other ways to make magic box
    int magicSquares[7][3][3] = {
        { {4, 3, 8}, {9, 5, 1}, {2, 7, 6} },
        { {2, 9, 4}, {7, 5, 3}, {6, 1, 8} },
        { {6, 7, 2}, {1, 5, 9}, {8, 3, 4} },
        { {6, 1, 8}, {7, 5, 3}, {2, 9, 4} },
        { {8, 3, 4}, {1, 5, 9}, {6, 7, 2} },
        { {4, 9, 2}, {3, 5, 7}, {8, 1, 6} },
        { {2, 7, 6}, {9, 5, 1}, {4, 3, 8} }
    };
    // Go through each possible box
    int subCost = 0;
    for(int sqPos = 0; sqPos < 7; sqPos++){
        // Check each row and col of given box
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                // For each row and col calculate absolute difference 
                // of each value in [row][col] with the 8 correct 
                // ways to make magic box
                subCost += abs(magicSquares[sqPos][row][col] - s[row][col]);
            }
        }
        // Update cost
        if( cost >= subCost){
            cost = subCost;
        }
        subCost = 0;
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

