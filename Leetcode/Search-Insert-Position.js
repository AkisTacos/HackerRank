/*
* Aki Saito
* Leetcode - Easy
* Search Insert Position
* July 10, 2019
* Language: Javascript
*/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
 
var searchInsert = function(nums, target) {
    var position;
    nums.forEach(function(n, i) {
       if (n == target) {
           position = i;
       } 
    });
    // If not found return index of where it would be if it were inserted in order.
    if (position == undefined) {
        nums.push(target);
        nums.sort(function(a, b){return a-b});
        // Look again
        nums.forEach(function(n, i) {
           if (n == target) {
               position = i;
               
           } 
        });
    }
    return position;
};

