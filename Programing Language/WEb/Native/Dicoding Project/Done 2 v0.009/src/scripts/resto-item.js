document.addEventListener('DOMContentLoaded', async () => {
  const apiUrl = 'https://restaurant-api.dicoding.dev'
  const response = await fetch(`${apiUrl}/list`)
  const data = await response.json()
  const resto = data.restaurants
  // const imgId = resto.pictureId

  const imgUrl = `${apiUrl}/images/large`

  console.log(resto)
  let dataCard = ''
  const screenSize = window.matchMedia('(max-width: 650px)')
  if (screenSize.matches) {
    resto.forEach(function (data) {
      dataCard += `
      <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.1.0/css/all.css" integrity="sha384-lKuwvrZot6UHsBSfcMvOkWwlCMgc0TaWr+30HWe3a4ltaBwTZhyTEggF5tJv8tbt" crossorigin="anonymous">
      
      
      <style>
        @import url('https://fonts.googleapis.com/css?family=Montserrat:300,400,700,800');
  
  
        * {
          displat
          color: white;
          padding: 0%;
          box-sizing: border-box;
          font-family: 'Montserrat', helvetica, arial, sans-serif;
          font-size: 15px;
          
        }
        
        .fan-art-resto {
          display: flex;
          max-height: 300px;
          margin: 0 auto;
          justify-item: center;
          justify-content: center;
        }
  
        .resto-info {
          
          padding: 24px;
          border-color: white;
        }
  
        .resto-info > h2 {
          font-weight: lighter;
        }
        
        .resto-info > p {
          margin-top: 10px;
          overflow: hidden;
          text-overflow: ellipsis;
          display: -webkit-box;
          -webkit-box-orient: vertical;
          -webkit-line-clamp: 10; /* number of lines to show */
        }
  
  
        .resto-card {
          position: relative;
          box-sizing: border-box;
          width: 80%;
          max-width: 800px;
          height: 800px;
          
          background-position: center;
          background-size: cover;
          margin: 4vh auto;
          border-radius: 25px;
          box-shadow: 2px 3px 12px rgba(0, 0, 0, .4);
          color: white;
          padding: 2vh 3%;
        }
  
        .resto-card:after{
          content: "";
          display: block;
          position: absolute;
          top: 0;
          left: 0;
          width: 100%;
          height: 100%;
          border-radius: 25px;
          background: linear-gradient(to right, rgba(40,40,60,1) 0%,rgba(40,40,60,0.5) 90%);
          background-blend-mode: multiply;
          will-change: transform;
          z-index: 0;
        }
        
        i {
          font-size: .7em;
          color: #ff5b84;
        }
        
        h1 {
          font-size: 3rem;
          position: relative;
          z-index: 10;
        }
  
        a{
          text-decoration: none;
          font-size: 3rem;
        }
  
        span {
          display: inline-block;
          position: relative;
          z-index: 5;
          margin-right: 80px;
          color: rgb(210, 210, 210);
        }
  
        p {
          position: relative;
          z-index: 10;
          font-size: 1.5em;
          width: 80%;
          height: 5%;
        }


        
      </style>
      <div class="resto-card lazyload" style="background-image: url(${imgUrl}/${data.pictureId});" title="${
        data.name
      }" alt="${data.name}">
        <br>
  
        <h1><a href="#">${data.name}</a></h1>
        <br>
        <span>City : <br>${data.city}</span>
        <span>Rating : <br>${data.rating} / 5</span>
        <p></p>
        <p>${data.description.slice(0, 200)} ... </p>
  
      </div>
          `
    })
  } else {
    resto.forEach(function (data) {
      dataCard += `
      <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.1.0/css/all.css" integrity="sha384-lKuwvrZot6UHsBSfcMvOkWwlCMgc0TaWr+30HWe3a4ltaBwTZhyTEggF5tJv8tbt" crossorigin="anonymous">
      
      
      <style>
        @import url('https://fonts.googleapis.com/css?family=Montserrat:300,400,700,800');
  
  
        * {
          color: white;
          padding: 0%;
          box-sizing: border-box;
          font-family: 'Montserrat', helvetica, arial, sans-serif;
          font-size: 15px;
          
        }
        
        .fan-art-resto {
          display: flex;
          max-height: 300px;
          margin: 0 auto;
          justify-item: center;
          justify-content: center;
        }
  
        .resto-info {
          
          padding: 24px;
          border-color: white;
        }
  
        .resto-info > h2 {
          font-weight: lighter;
        }
        
        .resto-info > p {
          margin-top: 10px;
          overflow: hidden;
          text-overflow: ellipsis;
          display: -webkit-box;
          -webkit-box-orient: vertical;
          -webkit-line-clamp: 10; /* number of lines to show */
        }
  
  
        .resto-card {
          position: relative;
          box-sizing: border-box;
          width: 80%;
          max-width: 800px;
          height: 800px;
          
          background-position: center;
          background-size: cover;
          margin: 4vh auto;
          border-radius: 25px;
          box-shadow: 2px 3px 12px rgba(0, 0, 0, .4);
          color: white;
          padding: 2vh 3%;
          
        }
  
        .resto-card:after{
          content: "";
          display: block;
          position: absolute;
          top: 0;
          left: 0;
          width: 100%;
          height: 100%;
          border-radius: 25px;
          background: linear-gradient(to right, rgba(40,40,60,1) 0%,rgba(40,40,60,0.5) 90%);
          background-blend-mode: multiply;
          will-change: transform;
          z-index: 0;
        }
        
        i {
          font-size: .7em;
          color: #ff5b84;
        }
        
        h1 {
          font-size: 3rem;
          position: relative;
          z-index: 10;
        }
  
        a{
          text-decoration: none;
          font-size: 3rem;
        }
  
        span {
          display: inline-block;
          position: relative;
          z-index: 5;
          margin-right: 80px;
          color: rgb(210, 210, 210);
        }
  
        p {
          position: relative;
          z-index: 10;
          font-size: 1.5em;
          width: 80%;
          height: 5%;
        }
  
  
        @media only screen and (max-width: 650px) {
          p {
            font-size: 1.4em;
          }
        }
      </style>
      <div class="resto-card lazyload" style="background-image: url(${imgUrl}/${data.pictureId});" title="${data.name}" alt="${data.name}">
        <br>
        <h1><a href="#">${data.name}</a></h1>
        <br>
        <span>City : <br>${data.city}</span>
        <span>Rating : <br>${data.rating} / 5</span>
        <p></p>
        <p>${data.description.slice(0, 600)} ... </p>
  
  
      </div>
          `
    })
  }

  document.querySelector('#list').innerHTML = dataCard
  console.log(resto)
})
