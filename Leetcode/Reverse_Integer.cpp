/* Aki Saito
* Leetcode - Easy
* Reverse Integer
* June 10, 2019
* Language: C++
*/ 

class Solution {
public:
    
    /*
    *   Reverses an integer
    *
    *	@param int
    *	@return int
    */
    int reverse(int x) {
        // Check if negative or positive
        // If negative switch to positive
        bool isSigned = false;
        long long riskyNum = x;
        if(x < 0)
        {
            isSigned = true; 
            riskyNum *= -1;
        }
        
        // Change to string
        string strNum = to_string(riskyNum);
        
        // Take each character and swap from 1st to last until middle
        for(int i = 0; i < strNum.length()/2; i++)
        {
            swap(strNum.at(i), strNum.at(strNum.length() - 1 - i));
        }
        
        // Convert back to integer
        riskyNum = stol(strNum);
        
        // Check for overflow
        if(riskyNum > INT_MAX || riskyNum < INT_MIN)
        {
            x = 0;
        }
        else 
        {
            x = riskyNum;  
        }
        
        if(isSigned == true)
        {
            x *= -1;
        }
        return x;
    }
};

