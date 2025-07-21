const movieList = [
    {
      title: "Batman",
      year: 1989,
      director: "Tim Burton",
      imdbRating: 7.6
    },
    {
      title: "Batman Returns",
      year: 1992,
      director: "Tim Burton",
      imdbRating: 7.0
    },
    {
      title: "Batman Forever",
      year: 1995,
      director: "Joel Schumacher",
      imdbRating: 5.4
    },
    {
      title: "Batman & Robin",
      year: 1997,
      director: "Joel Schumacher",
      imdbRating: 3.7
    },
    {
      title: "Batman Begins",
      year: 2005,
      director: "Christopher Nolan",
      imdbRating: 8.3
    },
    {
      title: "The Dark Knight",
      year: 2008,
      director: "Christopher Nolan",
      imdbRating: 9.0
    },
    {
      title: "The Dark Knight Rises",
      year: 2012,
      director: "Christopher Nolan",
      imdbRating: 8.5
    }
  ];


// // IMPERATIVE CODING
// // Get movie titles
// const titles = [];
// for (const movie of movieList) {
//   titles.push(movie.title);
// }
// console.log(titles);

// // Count movies by Christopher Nolan
// const nolanMovieList = [];
// for (const movie of movieList) {
//   if (movie.director === "Christopher Nolan") {
//     nolanMovieList.push(movie);
//   }
// }
// console.log('There are ' + nolanMovieList.length + ' Christopher Nolan movies in the list.');

// // Get titles of movies with an IMDB rating greater or equal to 7.5
// const bestTitles = [];
// for (const movie of movieList) {
//   if (movie.imdbRating >= 7.5) {
//     bestTitles.push(movie.title);
//   }
// }
// console.log(bestTitles);

// // Compute average movie rating of Christopher Nolan's movies
// let ratingSum = 0;
// let averageRating = 0;
// for (const movie of nolanMovieList) {
//   ratingSum += movie.imdbRating;
// }
// averageRating = ratingSum / nolanMovieList.length;
// console.log(averageRating);

// //STEP 1: LIMIT MUTATION (make const variables and split code in functions)
// // Get movie titles
// const titles = () => {
//   const titles = [];
//   for (const movie of movieList) {
//     titles.push(movie.title);
//   }
//   return titles;
// };

// const nolanMovieList = [];

// // Get movies by Christopher Nolan
// const nolanMovies = () => {
//   for (const movie of movieList) {
//     if (movie.director === "Christopher Nolan") {
//       nolanMovieList.push(movie);
//     }
//   }
// };

// // Get titles of movies with an IMDB rating greater or equal to 7.5
// const bestTitles = () => {
//   const bestTitles = [];
//   for (const movie of movieList) {
//     if (movie.imdbRating >= 7.5) {
//       bestTitles.push(movie.title);
//     }
//   }
//   return bestTitles;
// };

// // Compute average rating of Christopher Nolan's movies
// const averageNolanRating = () => {
//   let ratingSum = 0;
//   for (const movie of nolanMovieList) {
//     ratingSum += movie.imdbRating;
//   }
//   return ratingSum / nolanMovieList.length;
// };

// console.log(titles());
// nolanMovies();
// console.log(nolanMovieList.length);
// console.log(bestTitles());
// console.log(averageNolanRating());



// //STEP 2: Make PURE FUNCTIONS

// // Get movie titles
// const titles = movies => {
//   const titles = [];
//   for (const movie of movies) {
//     titles.push(movie.title);
//   }
//   return titles;
// };

// // Get movies by Christopher Nolan
// const nolanMovies = movies => {
//   const nolanMovies = [];
//   for (const movie of movies) {
//     if (movie.director === "Christopher Nolan") {
//       nolanMovies.push(movie);
//     }
//   }
//   return nolanMovies;
// };

// // Get titles of movies with an IMDB rating greater or equal to 7.5
// const bestTitles = movies => {
//   const bestTitles = [];
//   for (const movie of movies) {
//     if (movie.imdbRating >= 7.5) {
//       bestTitles.push(movie.title);
//     }
//   }
//   return bestTitles;
// };

// // Compute average rating of a movie list
// const averageRating = movies => {
//   let ratingSum = 0;
//   for (const movie of movies) {
//     ratingSum += movie.imdbRating;
//   }
//   return ratingSum / movies.length;
// };

// console.log(titles(movieList));
// const nolanMovieList = nolanMovies(movieList);
// console.log(nolanMovieList.length);
// console.log(bestTitles(movieList));
// console.log(averageRating(nolanMovieList));


//STEP 3: Use Array Functions. Here is your Declarative Coding Approach ends for now...

// Get movie titles
const titles=(m)=> m.map(elem=>elem.title);  


// Count movies by Christopher Nolan
const nolanMovies=(m)=>m.filter(elem=>elem.director==="Christopher Nolan");


// Get titles of movies with an IMDB rating greater or equal to 7.5
const bestTitle=(m)=>m.filter(elem=>elem.imdbRating>=7.5).map(elem=>elem.title);


// Compute average movie rating of Christopher Nolan's movies
const avgRating=(m)=>m.reduce((acc,m)=>acc+m.imdbRating,0)/m.length;

//Our Main
console.log(titles(movieList));
const nolanMovieList=nolanMovies(movieList);
console.log('There are ' + nolanMovieList.length + ' Christopher Nolan movies in the list.');
console.log(bestTitle(movieList));
console.log(avgRating(nolanMovieList));