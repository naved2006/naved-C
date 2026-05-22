let units: number = 120;
let bill: number;

if (units <= 100) {
    bill = units * 5;
} else {
    bill = units * 8;
}

console.log( bill);