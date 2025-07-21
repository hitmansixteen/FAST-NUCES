const Person=(props)=>{
    let msg="Appropriate"
    // if(props.isYoung===true)
    // {
    //     msg="Appropriate"
    // }
    // else
    // {
    //     msg="Inappropriate"
    // }
    return (
        <div>
            {props.isYoung===true && <h3>{msg}</h3>}
            <p>Im {props.name} having age {props.age} </p>
            <p>{props.children}</p>
        </div>
    )
  
}

export default Person;