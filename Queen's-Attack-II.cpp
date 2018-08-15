// HackerRank - Medium
// Equalize the Array
// August 9, 2018
// Language: C++
// 
/* Description:

You will be given a square chess board with one queen and a number of obstacles placed on it. 
Determine how many squares the queen can attack.

A queen is standing on an n x n chessboard. 
The chess board's rows are numbered from 1 to n, going from bottom to top. 
Its columns are numbered from 1 to n, going from left to right. 
Each square is referenced by a tuple, (r, c), describing the row, r, and column, c, where the square is located.

The queen is standing at position (r_q, c_q). 
In a single move, she can attack any square in any of the eight directions (left, right, up, down, and the four diagonals). 
In the diagram below, the green circles denote all the cells the queen can attack from (4, 4):

There are obstacles on the chessboard, each preventing the queen from attacking any square beyond it on that path. 
For example, an obstacle at location (3, 5) in the diagram above prevents the queen from attacking cells (3, 5), (2, 6), and (1, 7):

Given the queen's position and the locations of all the obstacles, find and print the number of squares the queen can attack from her position at (r_q, c_q).

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;
    
    // n = length of board
    // k = number of obstacles
    // r_q = queen's position (row)
    // c_q = queen's position (column)
    
    int result = 0;
    
    // Count spaces for queen to attack vertical and horizontal
    int topCount = n - r_q; //    Max available space above Queen
    int bottomCount = r_q - 1; // Max available space below Queen
    int leftCount = c_q - 1; //   Max available space left of Queen
    int rightCount = n - c_q; //  Max available space right of Queen
    
    // Count spaces for queen to attack diagonal
    int topRight = min(topCount, rightCount);
    int topLeft = min(topCount, leftCount);
    int bottomRight = min(bottomCount, rightCount);
    int bottomLeft = min(bottomCount, leftCount);
    
    // Check the obstacles
    for(int i = 0; i < k; i++){
        int r_o, c_o;
        cin >> r_o >> c_o;
        
        // Check vertical
        if(c_q == c_o){
        	// Top
            if((r_o > r_q) && (r_o - r_q - 1 < topCount))
                topCount = r_o - r_q - 1;
            // Bottom
            else if((r_o < r_q) && (r_q - r_o - 1 < bottomCount))
                bottomCount = r_q - r_o - 1;
        }
        // Check horizontal
        else if(r_q == r_o){
        	// Right
            if((c_o > c_q) && (c_o - c_q - 1 < rightCount))
                rightCount = c_o - c_q - 1;
            // Left
            else if((c_o < c_q) && (c_q - c_o - 1 < leftCount))
                leftCount = c_q - c_o - 1;
        }
        // Check Diag from top right to bottom left
        else if(r_o - r_q == c_o - c_q){
        	// Top Right
            if((r_o > r_q) && (r_o - r_q - 1 < topRight))
                topRight = r_o - r_q - 1;
            // Bottom Left
            else if((r_q > r_o) && (r_q - r_o - 1 < bottomLeft))
                bottomLeft = r_q - r_o - 1;
        }
        // Check Diag from top left to bottom right
        else if(abs(r_o - r_q) == abs(c_o - c_q)){
        	// Top left
            if((r_o > r_q) && (r_o - r_q - 1 < topLeft))
                topLeft = r_o - r_q - 1;
            // Bottom left
            else if((r_q > r_o) && (r_q - r_o - 1 < bottomRight))
                bottomRight = r_q - r_o - 1;
        }
    }
    result = topCount + bottomCount + leftCount + rightCount + topRight + topLeft + bottomRight + bottomLeft;
    cout << result;
    return 0;
}


