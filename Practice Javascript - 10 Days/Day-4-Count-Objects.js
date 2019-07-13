/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 4: Count Objects
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

/*
 * Return a count of the total number of objects 'o' satisfying o.x == o.y.
 * 
 * Parameter(s):
 * objects: an array of objects with integer properties 'x' and 'y'
 */

/**
*   Return a count of total number of objects 'o' satisfying o.x == o.y
*   @param {Objects} objects - Our given o's
*   @return {Integer} count - Number of objects that satisfy o.x == o.y
**/

function getCount(objects) {
    var count = 0;
    for (let e of objects) {
        if (e.x == e.y) {
            count++;
        }
    }
    return count;
}

