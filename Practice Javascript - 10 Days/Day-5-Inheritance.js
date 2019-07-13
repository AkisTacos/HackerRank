// Aki Saito
// HackerRank - Easy
// Javascript - Day 5: Inheritance
// July 12, 2019
// Language: Javascript
// 

class Rectangle {
    constructor(w, h) {
        this.w = w;
        this.h = h;
    }
}

/*
 *  Write code that adds an 'area' method to the Rectangle class' prototype
 */
/*
*   'area' method to the Rectangle class' prototype
*   @param {} No params 
*   @return {Objects from Rectangle Class} w, h - From 'Rectangle'
*/
Rectangle.prototype.area = function () {
    return (this.w * this.h);
}

/*
*   Square class that inherits from Rectangle and implements its class constructor
*   @param {Object} side - Square's side
*   @return - Nothing is returned
*/
class Square extends Rectangle {
    constructor(side) {
        super(side);
        this.w = side;
        this.h = side;
    }
}

