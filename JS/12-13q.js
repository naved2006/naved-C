"use strict";
console.log("Generate the multiplication table of a given number");
let num = 5;
for (let i = 1; i <= 10; i++) {
    console.log(num + " x " + i + " = " + (num * i));
}
console.log("Generate multiplication tables from 1 to 10");
for (let num = 1; num <= 10; num++) {
    console.log("Table of " + num);
    for (let i = 1; i <= 10; i++) {
        console.log(num + " x " + i + " = " + (num * i));
    }
}
