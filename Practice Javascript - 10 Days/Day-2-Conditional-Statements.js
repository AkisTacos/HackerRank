/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 2: Conditional Statements
* July 08, 2019
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

/*
    *   Find and return grade
    *
    *      @param int
    *      @return char
*/

/*
*   Returns the appropriate letter grade
*   @param {Number} score - A Number score for grade
*   @return {Character} grade - A letter grade for score
*/

function getGrade(score) {
    let grade;

    // Using if and else conditional statements
    if (score > 25) {
        grade = 'A';
    } else if (score == 25 || score > 20) {
        grade = 'B';
    } else if (score == 20 || score > 15) {
        grade = 'C';
    } else if (score == 15 || score > 10) {
        grade = 'D';
    } else if (score == 10 || score > 5) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    return grade;
}


function main() {
    const score = +(readLine());
    
    console.log(getGrade(score));
}