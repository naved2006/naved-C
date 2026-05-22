let purchase: number = 6000;
let discount: number;

if (purchase > 5000) {
    discount = purchase * 0.15;
} else {
    discount = purchase * 0.05;
}

let finalAmount = purchase - discount;

console.log("Purchase Amount = ₹" + purchase);
console.log("Discount = ₹" + discount);
console.log("Final Amount = ₹" + finalAmount);