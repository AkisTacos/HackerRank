// Aki Saito
// HackerRank - Easy
// Vector-Erase
// April 15, 2019
// Language: C++
// 
/* Description:
    
    Sets are a part of the C++ STL. Sets are containers that stor unique elements following
    a specific order. Here are some of the frequently used memebr functions of sets:
    
    Declaration:
      set<int> s; // Creates a set of integers.
      
    Size:
      int length = s.size(); // Returns the size of the set
      
    Insert:
      s.insert(x); // Inserts an integer x into the set s.
      
    Erasing an element:
      s.erase(val); // Erases an integer val from the set s.
      
    Finding an element:
      set<int>::iterator itr = s.find(val); // Gives the iterator to the element val if it's found
      // Otherwise returns s.end();
      
     Coming to the problem, you will be given Q queries. Each query is of one of the following three
     types:
     
     **1** _**x**_ : Add an element **x** to the set.
     **2** _**x**_ : Delete an element **x** from the set. (If the number **x** is not present in the set, then do nothing)
     **3** _**x**_ : If the number **x** is present in the set, then print "Yes"(without quotes) else print "No"(without quotes)

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void actions(set<int> &r_set, int typ, int val){
  set<int>::iterator itr;

  if(typ == 1){
        r_set.insert(val);
      } else if(typ == 2){
        r_set.erase(val);
      } else {
        itr = r_set.find(val);
        if(itr == r_set.end())
          cout << "No" << endl;
        else
          cout << "Yes" << endl;
      }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    // Declarations
    int size, i, type, value;
    set<int> mySet;
    
    // Check type
    cin >> size;
    for(i = 0; i < size; i++){
      cin >> type >> value;
      actions(mySet, type, value);
    }
    
    return 0;
}


