/*
* Aki Saito
* HackerRank - Easy
* Javascript - Day 4: Classes
* July 10, 2019
* Language: Javascript
*/

/**
*   Create Polygon class with constructor and 'perimeter' method.
*   @param {Integers[]} sides - Our given array with polygon sides
*   @return {Integer} total - Our calculated perimeter
**/

function Polygon(sides) {
    this.perimeter = function () {
        var total = 0;
        for (let e of sides) {
            total = total + e;
        }
        return total;
    }
}



const rectangle = new Polygon([10, 20, 10, 20]);
const square = new Polygon([10, 10, 10, 10]);
const pentagon = new Polygon([10, 20, 30, 40, 43]);

console.log(rectangle.perimeter());
console.log(square.perimeter());
console.log(pentagon.perimeter());