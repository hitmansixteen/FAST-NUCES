import './Person.css'

const Person=(props)=>{
    return (
       <div className='Person'>
            <p onClick={props.clicked}>Hi! my name is {props.n} and I'm {props.a} years old</p>
            <input type="text" value={props.n} onChange={props.changeNme}></input>
        </div>
    );
    
}
export default Person;