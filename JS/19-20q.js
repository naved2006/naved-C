"use strict";
console.log("Check whether a number is a Palindrome or not");
let num = 121;
let original = num;
let reverse = 0;
while (num > 0) {
    let digit = num % 10;
    reverse = reverse * 10 + digit;
    num = Math.floor(num / 10);
}
if (original === reverse) {
    console.log("Palindrome Number");
}
else {
    console.log("Not a Palindrome Number");
}
console.log("Check whether a number is an Armstrong Number or not");
let num1 = 153;
let real = num;
let sum = 0;
while (num > 0) {
    let digit = num % 10;
    sum = sum + (digit * digit * digit);
    num = Math.floor(num / 10);
}
if (sum === original) {
    console.log("Armstrong Number");
}
else {
    console.log("Not an Armstrong Number");
}
