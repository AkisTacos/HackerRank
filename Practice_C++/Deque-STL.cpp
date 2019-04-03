// Aki Saito
// HackerRank - Medium
// Deque-STL
// April 2, 2019
// Language: C++
// Credit to mohitsin3232 for helping with very strict TLE 
/* Description:
	Double ended queue or Deque(part of C++ STL) are sequence containers with 
	dynamic sizes that can be expanded or contracted on both ends (either its 
	front or its back). 

	The member functions of deque that are mainly used are:
	Deque Template:
		std::deque<value_type>
	Declaration:
		deque<int> mydeque; //Creates a double ended queue of deque of int type
	Size
		int length = mydeque.size(); //Gives the size of the deque
	Push
		mydeque.push_back(1); //Pushes element at the end
		mydeque.push_front(2); //Pushes element at the beginning
	Pop
		mydeque.pop_back(); //Pops element from the end
		mydeque.pop_front(); //Pops element from the beginning
	Empty
		mydeque.empty() //Returns a boolean value which tells whether the deque is empty or not
	
	Given a set of arrays of size N and an integer K, you have to find the
	maximum integer for each and every contiguous subarray of size K for each
	of the given arrays.
*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> myDeque;

    int i;
    for(i = 0; i < k; i++){
    	while(!myDeque.empty() && arr[i] >= arr[myDeque.back()])
    		myDeque.pop_back();
    	myDeque.push_back(i);
    }
    for(i = k; i < n; i++){
    	cout << arr[myDeque[0]] << ' ';
    	while(!myDeque.empty() && myDeque[0] <= i-k)
    		myDeque.pop_front();
    	while(!myDeque.empty() && arr[i] >= arr[myDeque.back()])
    		myDeque.pop_back();
    	myDeque.push_back(i);
    }
    cout << arr[myDeque[0]] << " \n";

}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}

