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
  let [text,changeText]=useState("Yes")
  let btnHandler=()=> {
    //return personArr[1].name="ok"
    //personArr[1].name="ok"
    let newarray=[...personArr]
    newarray[1].name="ok"
    return setPersonsArr(newarray)
  }


  let btnHandler1=()=> {
    return changeText(function(prevState){
      if(prevState==="Yes")
        return "No"
      else
        return "Yes"
    })
  }

  return (
    <div className="App">
      <h1>Persons List</h1>

      {
        personArr.map(function(obj){
          return <Person n={obj.name} a={obj.age} y={obj.isYoung}/>
        })
      }

      <button onClick={btnHandler}>Click me</button>
      <br/>
      <button onClick={btnHandler1}>{text}</button>
    </div>
  );
}

export default App;
