"use strict";
console.log("Find the sum of numbers from 1 to 10.");
let sum1 = 0;
for (let i = 1; i <= 10; i++) {
    sum1 += i;
}
console.log("Sum 1 to 10 =", sum1);
console.log("Find the sum of all even numbers from 1 to 50.");
let evenSum = 0;
for (let i = 1; i <= 50; i++) {
    if (i % 2 === 0) {
        evenSum += i;
    }
}
console.log("Sum of even numbers =", evenSum);
console.log("Find the sum of all odd numbers from 1 to 50.");
let oddSum = 0;
for (let i = 1; i <= 50; i++) {
    if (i % 2 !== 0) {
        oddSum += i;
    }
}
console.log("Sum of odd numbers =", oddSum);
