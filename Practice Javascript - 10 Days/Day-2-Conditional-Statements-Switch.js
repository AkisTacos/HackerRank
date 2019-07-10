/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 2: Conditional Statements: Switch
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
*   Takes the first letter of string and returns the letter of corresponding lisit
*   @param {String} s - Our given string
*   @return {Char} - The character that corresponds to the list
*/

function getLetter(s) {
    let letter;

    // Save first letter of string
    let firstLtr = s.charAt(0);
    // Using Switch for conditional statements
    switch (firstLtr) {
        case 'a' || 'e' || 'i' || 'o' || 'u':
            letter = 'A';
            break;
        case 'b' || 'c' || 'd' || 'f' || 'g':
            letter = 'B';
            break;
        case 'h' || 'j' || 'k' || 'l' || 'm':
            letter = 'C';
            break;
        default:
            letter = 'D';
    }
    
    return letter;
}


function main() {
    const s = readLine();
    
    console.log(getLetter(s));
}