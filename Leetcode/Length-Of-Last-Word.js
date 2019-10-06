/*
* Aki Saito
* Leetcode - Easy
* Length of Last Word
* October 5, 2019
* Language: Javascript
*/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
        // Check empty
        if (s === "")
        	return 0;

        var splitStr = s.split(" ");
    
        splitStr = splitStr.filter(function(e){return e});
        var lastWord = splitStr[splitStr.length - 1];
    
        return (lastWord == null ? 0 : lastWord.length);
};