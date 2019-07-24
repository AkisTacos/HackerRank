// Aki Saito
// HackerRank - Easy
// Conditional Statements
// April 3, 2019
// Language: C++
// 
/* Description:
	stringstream is a stream class to operate on strings. 
	It basically implements input/output operations on memory (string) based streams. 
	stringstream can be helpful in different type of parsing. 
	The following operators/functions are commonly used here

		Operator >> Extracts formatted data.

		Operator << Inserts formatted data.

		Method str() Gets the contents of underlying string device object.

		Method str(string) Sets the contents of underlying string device object.

		Its header file is sstream.
		One common use of this class is to parse comma-separated integers from a 
		string (e.g., "23,4,56").

			stringstream ss("23, 4, 56");
			char ch;
			int a, b, c;
			ss >> a >> ch >> b >> ch >> c; // a = 23, b = 4, c = 56

	You have to complete the function vector parseInts(string str). 
	str will be a string consisting of comma-separated integers, and you have 
	to return a vector of int representing the integers.
*/

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
	stringstream ss(str);
	vector<int> resultVec;
	char ch;
	int num;
	while(ss >> num){
		resultVec.push_back(num);
		ss >> ch;
	}
		
	return resultVec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}