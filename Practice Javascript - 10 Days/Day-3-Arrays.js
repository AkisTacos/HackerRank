/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 3: Arrays
* July 09, 2019
* Language: Javascript
*/

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

/**
*   Return the second largest number in the array.
*   @param {Number[]} nums - An array of numbers.
*   @return {Number} The second largest number in the array.
**/
function getSecondLargest(nums) {
    // Initialize and declare our vars
    var secondLargest = 0;
    var largest = 0;

    // Iterate through nums and compare our largest
    nums.forEach(function (e, i, array) {
        
        // First case is when next element is greater than largest
        if (largest < e) {
            // Update both secondLargest and largest
            secondLargest = largest;
            largest = e;
        }

        // Second case is when next element is less than largest but greater than secondLargest
        if (largest > e && secondLargest < e) {
            // Update only the secondLargest
            secondLargest = e;
        }
    });

    return secondLargest;
}

