import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';


ReactDOM.render(<App/>,document.getElementById('root'));

// //Imperative Programming
// const h1=document.createElement('h1');
// h1.textContent="this is imperative programming";
// document.getElementById('root').append(h1);
// console.log(h1);


// //JSX
// const element=<h1>this is declarative programming</h1>;
// //JSX returns simple JS Obect
// console.log(element);


// const elem=(<div>
//   <h1>this is declarative programming</h1>
//   <p>this is it</p>
//   </div>);

////A Functional component
// function Elem(){
//   return(
//   <div>
//        <h1>this is declarative programming</h1>
//        <p>this is it</p>
//   </div>);
// }


////why we can't use append() instead of ReactDOM.render()
//document.getElementById('root').append(elem);


// function MainPage()
// {
//   return (
//     <div>
//        <header>
//           <h1>Why you want to study React</h1>
//        </header>
//       <ol>
//         <li>It is most useful and worldwide practice for developing Web Apps</li>
//         <li>Want to explore this Library </li>
//         <li>It supports custom components just like normal HTML</li>
//         <li>It has declarative approach</li>
//         <li>Code is managable and reusable</li>
//         <li>We can actually render our website quite fast</li>
//       </ol>
//       <footer>
//           Copyrights @ 2024
//       </footer>
//     </div>
//   );
// }


// function Header()
// {
//   return(
//     <header>
//     <h1>Why you want to study React</h1>
//   </header>
//   );
// }

// function MainContent()
// {
//   return (
// <ol>
//         <li>It is most useful and worldwide practice for developing Web Apps</li>
//         <li>Want to explore this Library </li>
//         <li>It supports custom components just like normal HTML</li>
//         <li>It has declarative approach</li>
//         <li>Code is managable and reusable</li>
//         <li>We can actually render our website quite fast</li>
//       </ol>

//   );
// }
// function Footer()
// {
//   return(
//     <footer>
//     Copyrights @ 2024
//   </footer>
//   );
// }

// function App()
// {
//   return (
//     <div>
//       <Header/>
//       <MainContent/>
//       <Footer/>
//     </div>
//   );
// }

// ReactDOM.render(<App/>,document.getElementById('root'));

