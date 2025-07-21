import logo from './logo.svg';
import './App.css';
import Person from './Person';
import { useState } from 'react';

function App() {
  let arr=[
    {name:"Hira",age:66,isYoung:false},
    {name:"Sara",age:22,isYoung:true},
    {name:"Ayan",age:44,isYoung:false},
    {name:"Affan",age:20,isYoung:true},
  ]

  let [personArr,setPersonsArr]=useState(arr)
  let btnHandler=()=> {

    let newarray=[...personArr]
    newarray[1].name="ok"
    return setPersonsArr(newarray)
  }


  let btnHandler2=(nme)=> {
    let newarray=[...personArr]
    newarray[1].name=nme
    return setPersonsArr(newarray)
  }
  return (
    <div className="App">
      <h1>Persons List</h1>

      {
        personArr.map(function(obj){
          return <Person n={obj.name} a={obj.age} y={obj.isYoung} clicked={()=>btnHandler2("Hashir")}/>
        })
      }

      <button onClick={btnHandler}>Click me</button>

    </div>
  );
}

export default App;
