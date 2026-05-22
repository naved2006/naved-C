let a: number = 10;
let b: number = 20;

console.log("Before Swap:");
console.log("a =", a);
console.log("b =", b);

a = a + b;
b = a - b;
a = a - b;

console.log("After Swap:");
console.log("a =", a);
console.log("b =", b);