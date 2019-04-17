// Aki Saito
// HackerRank - Easy
// Lower Bound-STL
// April 16, 2019
// Language: C++
// 
/* Description:
    
	Maps are a part of the C++ STL.
	Maps are associative containers that store elements formed by a combination 
	of a key value and a mapped value, following a specific order.

	The mainly used member functions of maps are:
		Map Template:
			std::map <key_type, data_type>

		Declaration:
			map<string,int>m; //Creates a map m where key_type is of type 
							  // string and data_type is of type int.
		
		Size:
			int length=m.size(); //Gives the size of the map.
		
		Insert:
			m.insert(make_pair("hello",9)); //Here the pair is inserted into 
											//the map where the key is "hello" and the value associated with it is 9.
		
		Erasing an element:
			m.erase(val); //Erases the pair from the map where the 
						  //key_type is val.
		
		Finding an element:
			map<string,int>::iterator itr=m.find(val); 
			//Gives the iterator to the element val if it is found otherwise returns m.end() .
		
		Ex: map<string,int>::iterator itr=m.find("Maps"); 
		//If Maps is not present as the key value then itr == m.end().
		
		Accessing the value stored in the key:
			To get the value stored of the key "MAPS" we can do m["MAPS"] or we 
			can get the iterator using the find function and then by itr->second
			we can access the value.

	You are appointed as the assistant to a teacher in a school and she is correcting 
	the answer sheets of the students. Each students can have multiple answer sheets.
	So the teacher has Q queries:

		1 X Y : Add the marks Y to the student whose name is X.
		2 X   : Erase the marks of the students whose name is X.
		3 X   : Print the marks of the students whose name is X. (if X didn't get any marks print 0).

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void actions(map<string, int> &m, int type, string name){
    int val;
    map<string, int>::iterator itr;
    if(type == 1){
        cin >> val;
        itr = m.find(name);
        if(itr != m.end())
            m[name] += val;
        else
            m.insert(make_pair(name, val));
    } else if(type == 2){
        m.erase(name);
    } else {
        itr = m.find(name);
        if(itr == m.end())
            cout << '0' << endl;
        else
            cout << m[name] << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    // Declaration
    int i, q, type, score;
    string sName;
    map<string, int> myMap;

    // Get type and data
    // Do actions according to type
    cin >> q;
    for(i = 0; i < q; i++){
        cin >> type >> sName;
        actions(myMap, type, sName);
    }

    return 0;
}




