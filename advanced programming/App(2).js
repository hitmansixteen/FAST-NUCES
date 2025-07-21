import logo from './logo.svg';
import './App.css';
import { useState,useEffect } from 'react';
import Post from './Post';
import axios from 'axios';
import NewPost from './NewPost';

const App=()=>{
  let [posts,setPosts]=useState([])
  useEffect(()=>{
    axios.get('https://jsonplaceholder.typicode.com/posts').then(response=>{
      console.log(response.data);
      let lessPosts=response.data.splice(0,4);
      setPosts(lessPosts)
    })
  },[])

    return(
      <div className='App'>
        {posts.map(p=>{
		return <Post t={p.title} b={p.body}/>
		}	
	)}
        <NewPost/>
      </div>
    );
  }
}



export default App;
















