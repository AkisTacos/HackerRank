/* Aki Saito
* Leetcode - Easy
* Roman To Integer
* June 1, 2019
* Language: C++
*/ 
class Solution {
public:
    
    /**
    *   Helper function to return correct values of roman numerals
    *   
    *   @param char
    *   @return int
    */
    int number(char roman)
    {
        unordered_map<char, int> numerals =
        { {'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        return numerals[roman];
    }
    
    /**
    *   Convert roman numeral string, s, into an integer value.
    *    
    *   @param string
    *   @return int       
    */
    int romanToInt(string s) {
        // IV 4, IX 9
        // XL 40, LC 90
        // CD 400, CM 900
        
        int result = 0, strSize = s.length() - 1;
        
        for(int first = strSize, second = -1; first >= 0; --first)
        {
            if( first == -1 || number(s[first]) >= number(s[second]) )
            {
                result += number(s[first]);
                second = first;
            }
            else
            {
                result -= number(s[first]);
            }
        }
        
        return result;
    }
};
