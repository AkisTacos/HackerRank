/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 5: Template Literals
* July 23, 2019
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
 * Determine the original side lengths and return an array:
 * - The first element is the length of the shorter side
 * - The second element is the length of the longer side
 * 
 * Parameter(s):
 * literals: The tagged template literal's array of strings.
 * expressions: The tagged template literal's array of expression values (i.e., [area, perimeter]).
 */

/*
*   Return a count of total number of objects 'o' satisfying o.x == o.y
*   @param {string[], Expression values[]} literals, expression - Tagged template literal's array of strings,
*   Tagged template literal's array of expressions value
*	@return {Number[]} array - Contains sorted s1 and s2
*/
function sides(literals, ...expressions) {
    // Save values
    let area = expressions[0];
    let perimeter = expressions[1];

    // Calculate formula
    let s1 = ( perimeter + (Math.sqrt((perimeter * perimeter) - 16 * area))) / 4;
    let s2 = ( perimeter - (Math.sqrt((perimeter * perimeter) - 16 * area))) / 4;
    
    // Sort results
    [s1, s2] = [s1, s2].sort();
    
    // Return sorted result
    return [s1, s2];
}


function main() {
    let s1 = +(readLine());
    let s2 = +(readLine());
    
    [s1, s2] = [s1, s2].sort();
    
    const [x, y] = sides`The area is: ${s1 * s2}.\nThe perimeter is: ${2 * (s1 + s2)}.`;
    
    console.log((s1 === x) ? s1 : -1);
    console.log((s2 === y) ? s2 : -1);
}