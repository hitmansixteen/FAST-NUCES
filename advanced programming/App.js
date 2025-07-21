
import './App.css';
import React, { Component } from 'react';
import Person from './Person';




function App () 
{

  let arr=[
    {name: "max", age:20, isYoung:true},
    {name:"harry",age:40, isYoung:false},
    {name:"hira",age:30, isYoung:true}
  ]
      
  	
    return (
      <div className="App">
        <h1>Hi this is React App!</h1>
        <p>Demo Project</p>
     
        {
          arr.map(elem=>{
    		    return <Person name={elem.name} age={elem.age} isYoung={elem.isYoung}/>;
  	        })
        }

        {/* <Person name={arr[0].name} age={arr[0].age}/>
        <Person name={arr[1].name} age="30">Hobby: Racing</Person>
        <Person name={arr[2].name} age="60"/> */}
       
      </div>
  );

  


}

export default App;
