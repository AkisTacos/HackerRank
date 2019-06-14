/* 
*   Aki Saito
*   Leetcode - Easy
*   Valid Parentheses
*   June 13, 2019
*   Language: C++
*/ 
class Solution {
public:
    
    /**
    *   Function to determine if the input string is a valid parentheses
    *   
    *   @param string
    *   @return bool
    */
    
    bool isValid(string s) 
{
    bool result = true;
    // Check if string is empty and if so return true
    if(s.empty())
    {
        return true;
    }
    
    // Use Stack to keep track
    stack<char> parenStack;
    char paren;
    
    // Loop through string char by char
    for(int i = 0; i < s.length(); i++)
    {
        // Check for open parentheses
        paren = s.at(i);

        if( paren == '(' ) 
        {
            parenStack.push('A');
        }
        else if( paren == '[' )
        {
            parenStack.push('B');
        }
        else if( paren == '{' )
        {
            parenStack.push('C');
        }
        
        // Check for dumb inputs
        if(parenStack.size() == 0)
        {
            return false;
        }
        
        // Check for close parentheses and if it matches open type
        if( paren == ')' )
        {
            // If it matches pop the top
            if( parenStack.top() == 'A' )
            {
                parenStack.pop();
            }
            else
            {
                result = false;
                break;
            }
        }
        if( paren == ']' )
        {
          if( parenStack.top() == 'B' )
          {
              parenStack.pop();
          }
          else
          {
              result = false;
              break;
          }
        }
        if( paren == '}' )
        {
            if( parenStack.top() == 'C' )
            {
                parenStack.pop();
            }
            else
            {
                result = false;
                break;
            }
        }
    }
    
    // Check for left over parentheses
    if(parenStack.size() != 0)
    {
        return false;
    }
    
    return result;
}

};
