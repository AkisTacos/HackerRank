/* Aki Saito
* Leetcode - Easy
* Remove Element
* June 21, 2019
* Language: C++
*/ 

class Solution {
public:
  
    /*
    *   Find and remove element
    *
    *	  @param vector<int>
    *	  @return int
    */

    int removeElement(vector<int>& nums, int val) {
        
        // Dumb inputs
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            if (nums[0] == val) {
                return 0;
            }
            return 1;
        }
        
        // Count number of finds
        int numFinds = 0, start = 0, end = nums.size() - 1;
        
        // Loop through list
        while (start != end + 1) {
            // Compare values
            if (nums[start] == val) {
                swap(nums[start], nums[end]);
                // Update
                end--;
                numFinds++;
            } else {
                // Update
                start++;
            }
        }
        return (nums.size() - numFinds);
    }
};
