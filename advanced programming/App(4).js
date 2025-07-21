import logo from './logo.svg';
import './App.css';
import React from 'react';
import Person from './Person';




const App =()=>{

 let arr= [
      {name: "Ahmad", age:20},
      {name:"harry",age:40},
      {name:"hira",age:30}
  ]
//make array a part of your state
  let [personsArr, setPersonsState]=useState(arr)

     const btnHandler=()=>
      {
	//console.log("clicked")
	////can't directly mutate state!!! it is dangerous that's why REACT doesn't recognize it!
	//personsArr[1].name="Aliyan"
	//return setPersonsState(personsArr)

	////do it properly without directly mutating the state variable
	let newArray=[...personsArr]
	newArray[1].name="Aliyan"
       return setPersonsState(newArray)
      }

    return (
      <div className="App">
        <h1>Hi this is React App!</h1>
        <p>Demo Project</p>
        
        {
          personsArr.map(elem=>{
    		    return <Person name={elem.name} age={elem.age} />;
  	        })
        }
	<button onClick={btnHandler}>Click Me</button>
      </div>
  );

  }


export default App;