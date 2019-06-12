// Aki Saito
// HackerRank - Easy
// Utopian Tree
// July 23, 2018
// Language: C++
// 
/* Description:

	The Utopian Tree goes through 2 cycles of growth every year. 
	Each spring, it doubles in height. Each summer, its height increases by 1 meter.
	
	Laura plants a Utopian Tree sapling with a height of 1 meter at the onset of spring. 
	How tall will her tree be after n growth cycles?
	For example, if the number of growth cycles is n = 5, the calculations are as follows:

	Period  Height
	0          1
	1          2
	2          3
	3          6
	4          7
	5          14

*/


#include <bits/stdc++.h>

using namespace std;

int treeGrowth(int cycles, int season, int height){
    // season will hold which season it is currently
    // 0 is spring
    // 1 is summer
    
    // Check if cycle is done
    if(cycles == 0)
        return height;
    
    // season 0 is double height
    if(season == 0) {    
        height *= 2;
        // recurse back till end of cycles
        return treeGrowth(cycles - 1, 1, height);        
    }
    // season 1 is add 1 to height
    else
        height += 1;
        // recurse back till end of cycles
        return treeGrowth(cycles - 1, 0, height); 
        
    return height;
}

// Complete the utopianTree function below.
int utopianTree(int n) {
    // n is the number of cycles 
    
    // Base cases
    if(n == 0)
        return 1;
    else if (n == 1)
        return 2;
    
    // If n is greater than 1
    return treeGrowth(n, 0, 1);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

