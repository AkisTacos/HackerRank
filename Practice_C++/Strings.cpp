// Aki Saito
// HackerRank - Easy
// Strings
// April 3, 2019
// Language: C++
// 
/* Description:
	C++ provides a nice alternative data type to manipulate strings, and the 
	data type is conveniently called string. 
	Some of its widely used features are the following:
		
		Declaration:
			string a = "abc";
		
		Size:
			int len = a.size();
		
		Concatenate two strings:
			string a = "abc";
			string b = "def";
			string c = a + b; // c = "abcdef".
		
		Accessing  element:
			string s = "abc";
			char   c0 = s[0];   // c0 = 'a'
			char   c1 = s[1];   // c1 = 'b'
			char   c2 = s[2];   // c2 = 'c'

			s[0] = 'z';         // s = "zbc"
		
		P.S.: We will use cin/cout to read/write a string.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string strA, strB;

    getline(cin, strA);
    getline(cin, strB);

    // 1st line length of strings
    cout << strA.length() << " " << strB.length() << endl;
    // 2nd line concatinate those two strings
    cout << strA << strB << endl;
    // 3rd swap first letters from the strings
    char a = strA.at(0), b = strB.at(0);
    strA.at(0) = b;
    strB.at(0) = a;
    cout << strA << " " << strB << endl;

    return 0;
}
