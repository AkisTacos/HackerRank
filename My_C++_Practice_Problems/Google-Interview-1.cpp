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
#include <vector>

using namespace std;

string program(string str)
{
  unsigned int i = 1;

  vector<char> vecStr;

  // First occurence
  size_t pos 

  return str;
}



// Only for testing
int main() {
  // Tester Variables
  string test1 = "abcdddf", test2 = "eegdhhhouweppp", test3 = "aabbccdddcba";
  string answer1 = "abcf", answer2 = "eegdouwe", answer3 = "";
  cout << endl;
  // Testing 1
  if((answer1 == program(test1)))
  {
    cout << "Test 1: Success!\n"; 
  } 
  else 
  {
    cout << "Test 1: Fail!\n"; 
  }

  // Testing 2
  if((answer2 == program(test2)))
  {
    cout << "Test 2: Success!\n";
  }
  else 
  {
    cout << "Test 2: Fail!\n"; 
  }
  
  // Testing 3
  if((answer3 == program(test3)))
  {
    cout << "Test 3: Success!\n";
  }
  else 
  {
    cout << "Test 3: Fail!\n"; 
  }

  cout << "\nCheck complete!" << endl;
  return 0;    
}

