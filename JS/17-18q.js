"use strict";
console.log("Find the largest digit in a number");
let num = 58327;
let largest = 0;
while (num > 0) {
    let digit = num % 10;
    if (digit > largest) {
        largest = digit;
    }
    num = Math.floor(num / 10);
}
console.log("Largest Digit =", largest);
console.log("Find the smallest digit in a number");
let num1 = 58327;
let smallest = 9;
while (num > 0) {
    let digit = num % 10;
    if (digit < smallest) {
        smallest = digit;
    }
    num = Math.floor(num / 10);
}
console.log("Smallest Digit =", smallest);
