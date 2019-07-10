/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 3: Throw
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
*   Return "YES" if positive number is given
*   Return "Negative Error" is negative, and "Zero Error" if 0
*   @param {Number} a - A number.
*   @return {String} Either error or string "YES".
**/
function isPositive(a) {
    if (a < 0) {
        throw new Error("Negative Error");
        return Error;
    }
    else if (a == 0) {
        throw new Error("Zero Error");
        return Error;
    }
    else {
        return "YES";
    }
}

