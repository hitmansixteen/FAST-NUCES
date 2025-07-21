import { useState,useEffect } from "react";
import axios from 'axios';


const NewPost=()=>{

    let [obj,setObj]=useState({
        	title:"",
        	body:""
    })
    let addPost=()=>{
        let post={
            title:this.state.title,
            body:this.state.body
        }
        axios.post('https://jsonplaceholder.typicode.com/posts',post).then(res=>console.log(res));
    }

        return(
            <div>
                <h2>Add New Post</h2>
                <p>Title:</p>
                <input type="text" onChange={(event)=>setObj({title:event.target.value})}/>
                <p>Body:</p>
                <input type="text" onChange={(event)=>setObj({body:event.target.value})}/>
                <button onClick={addPost}>Add</button>
            </div>
        );
}

export default NewPost;