/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 4: Create a Rectangle Object
* July 10, 2019
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
*   Return length, width, perimeter, and area of rectangle
*   @param {Integer, Integer} a, b - 'a' is length, 'b' is width
*   @return {Object} rec - Return object rec with length, width, perimeter, and area
**/

function Rectangle(a, b) {
    // Create new object rec
    var rec = new Object();
    
    // Initialize properties
    rec.length = a;
    rec.width = b;
    rec.perimeter = 2 * (a + b);
    rec.area = a * b;

    return rec;
}

