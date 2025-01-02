function fun() {
    console.log("Hello World");
    console.log("This is my first js function");
}

fun();

function sum(a, b) {
    console.log(a+b);
}

sum(220,330)

// arrow function

const arrowSum = (a, b) => {
    console.log(a+b);
};

arrowSum(4, 7);

let arr = [1, 2, 3, 4, 5];

arr.forEach((i) => {
    console.log(i**3);
})

let newArr = arr.map((val) => val**3);
console.log(newArr);

let evenArr = arr.filter((val) => val%2==0);
console.log(evenArr);

let s = arr.reduce((res, val) => res + val);
console.log(s);