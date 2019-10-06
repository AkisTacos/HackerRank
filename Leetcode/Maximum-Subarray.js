/*
* Aki Saito
* Leetcode - Easy
* Maximum Subarray
* October 5, 2019
* Language: Javascript
*/

/**
 * @param {number[]} nums
 * @return {number}
 */

 var maxSubArray = function(nums) {
    var maxNum = 0;
    var result = Number.MIN_SAFE_INTEGER + 1;
    
    for(let e of nums) {
        maxNum += e;
        result = Math.max(maxNum, result);
        
        if(maxNum < 0) {
            maxNum = 0;
        }
    }
    
    return result;
};