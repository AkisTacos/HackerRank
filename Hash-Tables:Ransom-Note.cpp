// Aki Saito
// HackerRank - Easy
// Hash Tables: Ransom Note
// February 8, 219
// Language: C++
// 
/* Description:
	Given N 2D points, we need to remove K points optimally such that remaining (N-K) points could be 
  covered by using a rectangular cloth with minimum area covered.
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int mSize;
    cin >> mSize;

    int nSize;
    cin >> nSize;
    
    map<string, int> magazine;
    vector<string> note;
    
    int word = 0;
    string buffer;
    for(int i = 0; i < mSize; i ++){
        cin >> buffer;
        magazine[buffer] += 1;
    }
    // Note
    for(int j = 0; j < nSize; j++){
        cin >> buffer;
        if(magazine[buffer] == 0){
            cout << "No";
            break;
        } else {
            magazine[buffer] -= 1;
            if(j == nSize - 1)
                cout << "Yes";
        }
    }
    
}
