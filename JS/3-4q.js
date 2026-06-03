"use strict";
console.log('Print all even numbers between 1 and 20.');
for (let i = 1; i <= 20; i++) {
    if (i % 2 === 0) {
        console.log(i);
    }
}
console.log('Print all odd numbers between 1 and 20.');
for (let i = 1; i <= 20; i++) {
    if (i % 2 !== 0) {
        console.log(i);
    }
}
