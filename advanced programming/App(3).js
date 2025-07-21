import logo from './logo.svg';
import './App.css';
import Person from './Person';
import { useState } from 'react';

function App() {
  let arr=[
    {id:1,name:"Hira",age:66,isYoung:false},
    {id:2,name:"Sara",age:22,isYoung:true},
    {id:3,name:"Ayan",age:44,isYoung:false},
    {id:4,name:"Affan",age:20,isYoung:true},
  ]

  let [show,showorhide]=useState(true)
  let [personArr,setPersonsArr]=useState(arr)

//for conditional rendering of persons list
  let btnHandler3=()=> {
    return showorhide(function(prev){
      if(prev===true)
        return false
      else
      return true
    })
  }
  let btnHandler4=(event,id)=> {
    const peronIndexToBeChanged=personArr.findIndex(p=>p.id===id);
    const personTobeChanged={...personArr[peronIndexToBeChanged]};
    personTobeChanged.name=event.target.value;
    const newList=[...personArr];
    newList[peronIndexToBeChanged]=personTobeChanged;
   return setPersonsArr(newList)
  }

  let deletePersonOnClick=()=>{
    //implement this
  }
  return (
    <div className="App">
      <h1>Persons List</h1>
    <button onClick={btnHandler3}>Show Persons</button>
      {
        show===true && personArr.map(function(obj){
          return <Person n={obj.name} a={obj.age} y={obj.isYoung} changeNme={(event)=>btnHandler4(event,obj.id)}/>
        })
      }

      
 
    </div>
  );
}

export default App;
