// Aki Saito
// HackerRank - Easy
// Practice>Interview Preparation Kit>Greedy Algorithms
// Lucky Balance
// March 16, 2019
// Language: javascript
// 
/* Description:
	Lena is preparing for an important coding competition that is 
	preceded by a number of sequential preliminary contests. 
	She believes in "saving luck", and wants to check her theory.
	Each contest is described by two integers, L[i] and T[i]:

	L[i] is the amount of luck associated with a contest.
	If Lena wins the contest, her luck balance will decrease by L[i];
	if she loses it, her luck balance will increase by L[i].

	T[i] denotes the contest's importance rating. 
	It's equal to 1 if the contest is important, and it's equal 
	to 0 if it's unimportant.

	If Lena loses no more than k important contests, 
	what is the maximum amount of luck she can have 
	after competing in all the preliminary contests? 
	This value may be negative.
*/

	'use strict';

const fs = require('fs');

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
// ================================================================
// Complete the luckBalance function below.
function luckBalance(k, contests) {
    let result = 0;
    contests.sort(function(a,b) {
        return b[0]-a[0];
    });
    console.log(contests);
    for(let i = 0; i < contests.length; i++){
        if(contests[i][1] == 0){
            result = result + contests[i][0];
        }
        else {
            if(k > 0){
                k--;
                result += contests[i][0];
            } else {
                result -= contests[i][0];
            }
        }
    }
    return result;
}
// ================================================================
function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nk = readLine().split(' ');

    const n = parseInt(nk[0], 10);

    const k = parseInt(nk[1], 10);

    let contests = Array(n);

    for (let i = 0; i < n; i++) {
        contests[i] = readLine().split(' ').map(contestsTemp => parseInt(contestsTemp, 10));
    }

    const result = luckBalance(k, contests);

    ws.write(result + '\n');

    ws.end();
}
