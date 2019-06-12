/* Aki Saito
* Leetcode - Easy
* Longest Common Prefix
* June 12, 2019
* Language: C++
*/ 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        // Check for null and vector size 0
        if(strs.empty() || strs.size() == 0)
        {
            return "";
        }
        
        // Loop through first word
        for(int i = 0; i < strs[0].length(); i++)
        {
            char test = strs[0].at(i);
            // Compare each other string
            for(int j = 1; j < strs.size(); j++)
            {
                if(i == strs[j].length() || strs[j].at(i) != test)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
