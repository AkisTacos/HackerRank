/* Aki Saito
* Leetcode - Easy
* Implement strStr()
* June 25, 2019
* Language: C++
*/ 

class Solution {
public:

    /*
    *   Find the substring in string and return position
    *
    *	  @param string, string
    * 	@return int
    */

    int strStr(string haystack, string needle) {
        // If haystack is empty
        if (needle.empty()) {
            return 0;
        }
        
        // Find 
        size_t find = haystack.find(needle);
        
        return find;
    }
};
