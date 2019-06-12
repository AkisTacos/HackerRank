// Aki Saito
// HackerRank - Medium
// Organizing Containers of Balls
// October 11, 2018
// Language: C++
// 
/* Description:

	David has several containers, each with a number of balls in it. 
	He has just enough containers to sort each type of ball he has into its own container. 
	David wants to sort the balls using his sort method.

	As an example, David has n = 2 containers and 2 different types of balls, 
	both of which are numbered from 0 to n - 1 = 1. 
	The distribution of ball types per container are described by an n x n matrix of integers, M[container][type]. 
	For example, consider the following diagram for M = [ [1, 4], [2, 3] ]:

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	// Run q-times for given querie amount
    int q;
    cin >> q;  
    for (int i = 1; i <= q; i++) {
    	// n is our Matrix size
        int n;
        cin >> n;
        // We will keep two arrays, "container" and "type" which will hold
        // every value for our "matrix array"
        long long container[n], type[n];
        // Give default value to our arrays
        for(int i = 0; i < n; i++)
            container[i] = type[i] = 0;
        // Assign correct value
        for (int i = 0; i < n; i++) {            
            for (int j = 0; j < n; j++) {
                int value;
                cin >> value;
                container[i] += value;
                type[j] += value;
            }
        }
        
        // It is possible for David if the total number of type in column is equal
        // to the number of balls in container so ( total_ball_container == ball_type )
        // We can achieve this by taking the sorted arrays of container and type
        // And comparing each value
        sort(container, container + n);
        sort(type, type + n);
        bool same = true;
        for(int i = 0; i < n; i++){
        	// If the values do not correspond then it's impossible
            if(container[i] != type[i]){
                same = false;
                break;
            }
        }
        if(result == true)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}

