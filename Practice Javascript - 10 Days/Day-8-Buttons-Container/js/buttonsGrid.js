// Javascript file for Day-8-Create-A-Button project
// 08-21-2019

var btnList = ["1", "2", "3", "6", "9", "8", "7", "4"];
var rotation = ["1", "2", "3", "6", "9", "8", "7", "4"];
var i;
var btn5 = document.getElementById("btn5");

btn5.addEventListener('click', function(){
    var btnTemp = rotation[7];
    for (i = 7; i > 0; i--) {
        rotation[i] = rotation[i-1];
    }
    rotation[0] = btnTemp;
    for (i = 0; i < 8; i++) {
        document.getElementById("btn" + btnList[i]).innerHTML = rotation[i];
    }
});
