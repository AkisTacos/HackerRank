/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 3: Try, Catch, and Finally
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
*   Using try, catch along with string split, reverse methods
*   reverse a string.
*   @param {String[]} s - Given string to reverse.
*   @return - None we will output the results using console.log()
**/
function reverseString(s) {
    // Using Try, catch, and finally try split string s
    var result;
    try {
        result = s.split("");
        result.reverse();
        result = result.join("");
    }
    catch(err) {
        console.log("s.split is not a function");
        result = s;
    }
    finally {
        console.log(result);
    }
}


function main() {
    const s = eval(readLine());
    
    reverseString(s);
}