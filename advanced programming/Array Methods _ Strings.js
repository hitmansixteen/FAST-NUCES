//Strings

console.log("Aliya".length);
console.log("HiraButt".toUpperCase());

const word = "koala";
console.log(word === "koala");    // true
console.log(word === "kangaroo");
console.log("Hira".toLowerCase()==="hira");

const namee="sarah";
for(let character of namee)
{
    console.log(character);
}
const namearr=Array.from(namee);
namearr.forEach((m)=>console.log(m));
const list="mon,tues,wed,";
const listarr=list.split(",");
console.log(listarr.length);

listarr.forEach(l=>console.log(l));

//Array methods


// const arr=['hi','bye',3,true].find(function(item)
// {
//     return item == 1;  //true==1 but true !==1
// });
// //console.log(arr);

// const anyNegative=[12,-2,45].some((item)=> item<0);

// console.log(anyNegative);

// const student=[{name:'Ayush',grade:90},{name:'Hira',grade:50},{name:'Ahmad',grade:80}];
// const filteredStudent=student.filter(item=> item.grade>70);
// console.log(filteredStudent);

// const squared=[2,3,4].map(item=>item**2);
// console.log(squared);

const arrOfobjs = [{ id: 'a' }, { id: 'b' }, { id: 'c' }];
const found = arrOfobjs.find(function (item) {
    return item.id === 'b';
});
console.log(found);

