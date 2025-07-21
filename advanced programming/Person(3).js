const Person=(props)=>{
    return (
       <div>
            <p onClick={props.clicked}>Hi! my name is {props.n} and I'm {props.a} years old</p>
            <input type="text" value={props.n}></input>
        </div>
    );
    
}
export default Person;