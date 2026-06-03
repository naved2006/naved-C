console.log("Check whether a number is a Palindrome or not");

let num: number = 121;
let original: number = num;
let reverse: number = 0;

while (num > 0) {
    let digit: number = num % 10;
    reverse = reverse * 10 + digit;
    num = Math.floor(num / 10);
}

if (original === reverse) {
    console.log("Palindrome Number");
} else {
    console.log("Not a Palindrome Number");
}

console.log("Check whether a number is an Armstrong Number or not");

let num1: number = 153;
let real: number = num;
let sum: number = 0;

while (num > 0) {
    let digit: number = num % 10;
    sum = sum + (digit * digit * digit);
    num = Math.floor(num / 10);
}

if (sum === original) {
    console.log("Armstrong Number");
} else {
    console.log("Not an Armstrong Number");
}

