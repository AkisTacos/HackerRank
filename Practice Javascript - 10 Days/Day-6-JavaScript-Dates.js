    
/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 6: JavaScript Dates
* July 25, 2019
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
 * Returns the Weekday of the input date
 * Parameter(s):
 * String: The date in string type
 * Return: [String] dayName - Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, or Saturday
 */


function getDayName(dateString) {
    let dayName = new Date(dateString);
    let weekdayStr = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    return weekdayStr[dayName.getDay()];
}


function main() {
    const d = +(readLine());
    
    for (let i = 0; i < d; i++) {
        const date = readLine();
        
        console.log(getDayName(date));
    }
}
