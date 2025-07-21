"use strict";

function sayHi()
{
    console.log("Say Hello to people");
}

sayHi();


console.log("hi"+"hello");
let h=null;
h=3;
{
    h=8;
    let g=4;
}
//console.log(g);
console.log(`2+2 is: ${2+2}`);
const x=4;
const y=9;
console.log(`${x} plus ${y} is ${x+y} `);

const e= Number("9");
console.log("2 + 2 is: "+ (2+2));


// const ps=require("prompt-sync");
// const prompt=ps();
// const input=Number(prompt("Enter a number"));
// console.log(typeof(input));

console.log(Boolean(""));

//console.log("0"===0);
// console.log(3.1e-3);
// let value=3.1 * (10**-3);
// console.log(value.toFixed(4));
console.log(2/0);
let a=11;
let b=9;
a??=b;
console.log(a);
console.log(Boolean(2));

let assign1=name=> "Say"+name;
console.log(assign1("HIra"));

let sum=(x,y)=>x+y;

console.log(sum(2));




const movies=[
    "Zootopia",
    "The legend of maula jutt",
    "top gun maverick"
];

for (let m of movies)
{
    console.log(m);
}
movies.unshift("New Jersey");
movies.splice(0,2);
movies.forEach(function (name,index)
{
    console.log("For Each Method at index "+index+" is : "+name);
});
console.log(movies.length);

movies.forEach((name,index)=>console.log(name+"at index: "+index ));

// // let a = Math.floor(Math.random());
// // while(a!==10)
// // {
// //     console.log(++a);
// // }
