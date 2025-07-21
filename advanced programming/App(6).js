import logo from './logo.svg';
import './App.css';
import Header from './Header';
import MainContent from './MainContent';
import Person from './Person';
import Footer from './Footer';
import { Component } from 'react';

// function App()
// {
//   return (
//     <div>
//        <Header/>
//        <MainContent/>
//        <Footer/>
//     </div>
//   );
// }

function App()
{

     return(
	<div>
	     <h1>This is react app</h1>
	     <Person/>
	     <Person/>
             <Person/>
        </div>
    );
   
}
export default App;
