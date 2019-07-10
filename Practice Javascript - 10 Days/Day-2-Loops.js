/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 2: Loops
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
*   Prints out all the vowels in string s, and consonants after
*   @param {string} s - Our given string
*   @return - Nothing is returned only console output
*/
function vowelsAndConsonants(s) {
    // Loop so that we check every letter in s
    var letter, i;
    var size = s.length;

    // Extract Vowels
    for (i = 0; i < size; i++) {
        letter = s.charAt(i);
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
            console.log(letter);
        }
    
    }

    // Extract Consonants
    for (i = 0; i < size; i++) {
        letter = s.charAt(i);
        if (letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u') {
            console.log(letter);
        }
    }
}


function main() {
    const s = readLine();
    
    vowelsAndConsonants(s);
}