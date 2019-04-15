// Aki Saito
// HackerRank - Easy
// Vector-Erase
// April 15, 2019
// Language: C++
// 
/* Description:
    
    You are provided with a vector of N integers. Then, you are given 2 queries.
    For the first query, you are provided with 1 integer, which denotes a position 
    in the vector. The value at this position in the vector needs to be erased. The
    next query consists of 2 integeres denoting a range of the positons in the vector.
    The elements which fall under that range should be removed. The second query is 
    performed on the updated vector which we get after performing the first query.
    
    The following are some useful vector functions:
    
      erase( int position ):
        v.erase(v.begin()+4); // Erases the fifth element of the vector v)
      
      erase( int start, int end);
        v.erase(v.begin()+2, v.begin()+5); // Erase all the elements from the third element to the fifth
         
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  vector<int> vec;
  int i, size, num, first, range_a, range_b;
  cin >> size;
  
  // Get Data
  for (i = 0; i < size; i++) {
    cin >> num;
    vec.push_back(num);
  }

  // Get erase position
  cin >> first;
  vec.erase(vec.begin() + first - 1);

  // Get erase range
  cin >> range_a >> range_b;
  vec.erase(vec.begin() + range_a - 1, vec.begin() + range_b - 1);

  // Print Results
  cout << vec.size() << endl;
  for (auto i : vec)
    cout << i << ' ';
  return 0;
}

