// Aki Saito
// HackerRank - Easy
// Input and Output
// April 1, 2019
// Language: C++
// 
/* Description:
	Read 3 numbers from stdin and print their sum to stdout.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num, result = 0;
    while(cin >> num)
        result += num;
    cout << result;
    return 0;
}