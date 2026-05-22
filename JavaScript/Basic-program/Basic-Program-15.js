"use strict";
let units = 120;
let bill;
if (units <= 100) {
    bill = units * 5;
}
else {
    bill = units * 8;
}
console.log(bill);
