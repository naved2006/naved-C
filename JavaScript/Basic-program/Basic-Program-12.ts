let a: number = 10;
let b: number = 20;

console.log("Before Swap:");
console.log("a =", a);
console.log("b =", b);

let temp: number;

temp = a;
a = b;
b = temp;

console.log("After Swap:");
console.log("a =", a);
console.log("b =", b);