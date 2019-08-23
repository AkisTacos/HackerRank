// Javascript file for Day-9-Binary-Calculator project
// 08-22-2019

var operand1;
var operand2;
var operator;
var input = "";
var inputA = "";
var inputB = "";
var result = 0;

    var numResult = document.getElementById("numResult");

var res = document.getElementById("res");
var btn1 = document.getElementById("btn1");
var btn0 = document.getElementById("btn0");
var btnSum = document.getElementById("btnSum");
var btnSub = document.getElementById("btnSub");
var btnMul = document.getElementById("btnMul");
var btnDiv = document.getElementById("btnDiv");
var btnEql = document.getElementById("btnEql");
var btnClr = document.getElementById("btnClr");

const convertNumberToBinary = number => {
    return (number >>> 0).toString(2);
}

btnEql.addEventListener('click', function() {
    input = res.innerHTML; 
    res.innerHTML = "";
    var splitStr = input.split('');
    for (var i = 0; i < splitStr.length; i++) {
        if (splitStr[i] == '+' || splitStr[i] == '-' || splitStr[i] == '*' || splitStr[i] == '/') {
            operator = splitStr[i];
            i++;
            for (var j = i; j < input.length; j++) {
                inputB = inputB + splitStr[j];  
            }
            break;
        }
        inputA = inputA + splitStr[i];
    }
    operand1 = parseInt(inputA, 2);
    operand2 = parseInt(inputB, 2);    
    switch(operator){
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            res.innerHTML = "Err";
    }
    numResult.innerHTML = result;
    res.innerHTML = convertNumberToBinary(result);
    input = "";
    inputA = "";
    inputB = "";
});

btnClr.addEventListener('click', function() {
    res.innerHTML = "";
    operand1 = "";
    operand2 = "";
    operator = "";
    input = "";
    inputA = "";
    inputB = "";
    result = 0;
});



btn1.addEventListener('click', function() {
   res.innerHTML = res.innerHTML + 1; 
});

btn0.addEventListener('click', function() {
   res.innerHTML = res.innerHTML + 0; 
});

btnSum.addEventListener('click', function() {
   res.innerHTML = res.innerHTML + '+'; 
});

btnSub.addEventListener('click', function() {
   res.innerHTML = res.innerHTML + '-'; 
});

btnMul.addEventListener('click', function() {
   res.innerHTML = res.innerHTML + '*'; 
});

btnDiv.addEventListener('click', function() {
   res.innerHTML = res.innerHTML + '/'; 
});
