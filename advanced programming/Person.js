function Person(props){

    return(
        <div>
        	<p>My name is {props.name} and Im {props.age} years old </p>
        	{props.children}
        </div>
        );
    

}
export default Person;



