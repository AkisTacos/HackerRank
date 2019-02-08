// Aki Saito
// HackerRank - Medium
// Hash-Tables: Ice Cream Parlor
// February 8, 2019
// Language: javascript
// 
/* Description:
	Given the value of money and the cost of each flavor for t trips to the Ice Cream Parlor,
  help Sunny and Johnny choose two distinct flavors such that they spend their entire pool
  of money during each visit.
  ID numbers are the 1-based index number associated with a cost.
  For each trip to the parlor, print the ID numbers for the two types of ice cream that Sunny
  and Johnny purchase as two space-separated integers on a new line. 
  You must print the smaller ID first and the larger ID second.
*/

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the whatFlavors function below.
function whatFlavors(cost, money) {
    const comp = {};

    for (let i = 0; i < cost.length; i++){
        if (comp[cost[i]] >= 0) {
            console.log(comp[cost[i]]+1, i+1);
        }
        comp[money - cost[i]] = i;
    }

}

function main() {
    const t = parseInt(readLine(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const money = parseInt(readLine(), 10);

        const n = parseInt(readLine(), 10);

        const cost = readLine().split(' ').map(costTemp => parseInt(costTemp, 10));

        whatFlavors(cost, money);
    }
}
