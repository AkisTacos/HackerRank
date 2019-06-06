// Google Interview 1
// On-site
/* 
Given a string, which may contain substrings constitued of 3 or more occurrences of the same character, remove all these substrings, including the initial ones (present in the initial string), and the ones created by removing a first substring. 
Return the modified substring.

Example:

  "abcdddf" -> "abcf"
  "eegdhhhouweppp" -> "eegdouwe"
  "aabbccddcba" -> "aabbcccba" -> "aabbba" -> "aaa" -> ""
*/ 
// 

#include <iostream>
#include <string>

using namespace std;

int main() {
  string testCase;
  getline(cin, testCase);

  cout << "Testing string: " << testCase << "..." << endl;

  bool complete = false;
  unsigned int i = 1;
  char checkChar = testCase.at(0);

  while (i != testCase.length())
  {
    if(checkChar != testCase.at(i)){
      checkChar = testCase.at(i);
      i++;
      continue;
    }
    
    i++;
  }

  return 0;    
}
