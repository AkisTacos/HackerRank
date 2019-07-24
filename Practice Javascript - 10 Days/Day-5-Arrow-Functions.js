// Aki Saito
// HackerRank - Easy
// Javascript - Day 5: Arrow Functions
// July 23, 2019
// Language: Javascript
// 

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Modify and return the array so that all even elements are doubled and all odd elements are tripled.
 * 
 * Parameter(s):
 * nums: An array of numbers.
 */
function modifyArray(nums) {
    // Create arrow function 
    var modifyArr = n => (n) = ( n % 2 ? n * 3 : n * 2 );

    // Remap the result and call it
    var newArr = nums.map(modifyArr);
    return newArr;
}

