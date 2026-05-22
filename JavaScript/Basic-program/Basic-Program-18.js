"use strict";
let purchase = 6000;
let discount;
if (purchase > 5000) {
    discount = purchase * 0.15;
}
else {
    discount = purchase * 0.05;
}
let finalAmount = purchase - discount;
console.log(purchase);
console.log(discount);
console.log(finalAmount);
