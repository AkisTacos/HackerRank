// Aki Saito
// HackerRank - Easy
// Javascript - Day 1: Functions
// May 14, 2019
// Language: Javascript
// 
/* Description:
    
	Objective:
		Today, we're discussing JavaScript functions. 
		Check out the attached tutorial for more details. 

	Task:
		Implement a function named factorial that has one parameter: an integer, n. 
		It must return the value of n! (i.e., n factorial).


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
 * Create the function factorial here
 */
 function factorial(number){
    if (number <= 1)
        return 1;
    return number * factorial(number - 1);
 }



function main() {
    const n = +(readLine());
    
    console.log(factorial(n));
}