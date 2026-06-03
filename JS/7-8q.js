"use strict";
console.log(" Print all numbers divisible by 5 between 1 and 50");
for (let i = 1; i <= 50; i++) {
    if (i % 5 === 0) {
        console.log(i);
    }
}
console.log("Print all numbers divisible by 3 and 5 between 1 and 100");
for (let i = 1; i <= 100; i++) {
    if (i % 3 === 0 && i % 5 === 0) {
        console.log(i);
    }
}
