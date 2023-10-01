class NavBar extends HTMLElement {
  constructor () {
    super()
    this.shadowDOM = this.attachShadow({ mode: 'open' })
  }

  connectedCallback () {
    const x = window.matchMedia('(max-width: 600px)')

    if (x.matches) {
      // If media query matches
      this.render_mobile()
    } else {
      this.render()
    }
  }

  //   set clickEvent(event) {
  //     this._clickEvent = event;
  //     this.render();
  //   }

  //   get value() {
  //     return this.shadowDOM.querySelector('#searchElement').value;
  //   }

  render () {
    this.shadowDOM.innerHTML = `
          <style>
            .search-container {
              z-index:100;
              max-width: 400p;
              box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
              padding: 20px;
              border-radius: 8rem 8rem 8rem 8rem;
              display: flex;
              position: sticky;
              top: 10px;
              background-color: #FFE6C7;
              align: center;
            }
            .search-container > input {
              width: 75%;
              font-size: 1rem;
              padding-left: 30px;
              padding-right: 30px;
              border: 1px solid #fff;
              border-radius: 8rem 8rem 15px 15px;
              
              background-color: #fff;
            }
            .search-container > input:focus {
              outline: 0;
              border: 10px solid rgb;
              font-weight: bold;
            }
            .search-container > input:focus::placeholder {
              font-weight: bold;
            }
            .search-container >  input::placeholder {
              color: rgb(41, 41, 41);
              font-weight: normal;
            }
            .search-container > button {
              width: 23%;
              cursor: pointer;
              margin: auto;
              padding: 10px 10px;
                

              
              background-color: #FFA559;
              color: #323232;
              border: 15px;
              border-radius: 20px 8rem 15px 8rem;
              text-transform: uppercase;
              font-weight: 800;
              font-size: 1.5rem;
              padding-left: 0;
              padding-right: 0;
              
    
            }
            .search-container > button:hover{
                background-color: #ed872f;
                color: #faf5f5;
            }


          </style>
          
          <div id="search-container" class="search-container">

    
            <button id="searchButtonElement" onclick="window.location.href='index.html';" type="button">Home</button>
            <button id="searchButtonElement" onclick="window.location.href='#';" type="button">Favorite</button>
            <button id="searchButtonElement" onclick="window.location.href='https://cutt.ly/sux';" type="button">About Us</button>
          </div>
          <div class="menu__toggler">
              <span></span>
          </div>
          <br>
        `

    this.shadowDOM
      .querySelector('#searchButtonElement')
      .addEventListener('click', this._clickEvent)
    this.shadowDOM
      .querySelector('#searchButtonElement')
      .addEventListener('Enter', this._clickEvent)
  }

  render_mobile () {
    this.shadowDOM.innerHTML = `
    <style>
    *{
      z-index: 1000;
    }

    .menu__toggler {
      position: flex;
      top: 30rem;
      left: 3rem;
      z-index: 1000;
      height: 28px;
      width: 28px;
      outline: none;
      cursor: pointer;
      display: flex;
      align-items: center;
      color: #faf5f5;
      
      padding: 1rem;
    }

    .menu__toggler span,
    .menu__toggler span::before,
    .menu__toggler span::after {
      position: absolute;
      content: '';
      width: 28px;
      height: 2.5px;
      background: #FFA559;
      border-radius: 20px;
      transition: 500ms cubic-bezier(0.77, 0, 0.175, 1);
    }
    .menu__toggler span::before {
      
      top: -8px;
    }
    .menu__toggler span::after {
      top: 8px;
    }
    .menu__toggler.active > span {
      background: transparent;
    }
    .menu__toggler.active > span::before, .menu__toggler.active > span::after {
      background: #000;
      top: 0px;
    }
    .menu__toggler.active > span::before {
      -webkit-transform: rotate(-225deg);
              transform: rotate(-225deg);
    }
    .menu__toggler.active > span::after {
      -webkit-transform: rotate(225deg);
              transform: rotate(225deg);
    }

    .menu {
      position: absolute;
      border-radius: 0 2rem 2rem 0;
      left: -100%
      z-index: 998;
      color: #005c9c;
      background: #FFE6C7;
      -webkit-clip-path: polygon(0 0, 100% 0, 100% 100%, 0% 100%);
              clip-path: polygon(0 0, 100% 0, 100% 100%, 0% 100%);
      width: 30%;
      height: 50%;
      padding: 100px;
      display: flex;
      flex-direction: column;
      justify-content: center;
      transition: 300ms left cubic-bezier(0.77, 0, 0.175, 1);
      width: 250px;
        left: -2500px;
        padding: 1rem;
    }
   
    .menu.active {
      left: 0;
    }
    .menu button {
      text-align: center;
      width: 75%;
      cursor: pointer;
      margin: auto;
      padding: 2rem;
      background-color: #FFA559;
      color: #323232;
      border: 15px;
      border-radius:  8rem;
      text-transform: uppercase;
      font-weight: 800;
      font-size: 14px;
      padding-left: 0;
      padding-right: 0;
    }

    .menu > button:hover{
      background-color: #ed872f;
      color: #faf5f5;
  }
    </style>

    <div class="menu">
      <button id="searchButtonElement" onclick="window.location.href='index.html';" type="button">Home</button>
      <button id="searchButtonElement" onclick="window.location.href='#';" type="button">Favorite</button>
      <button id="searchButtonElement" onclick="window.location.href='https://cutt.ly/sux';" type="button">About Us</button>
    </div>
    <div class="menu__toggler">
    <span></span>
    </div>


    `

    const toggler = this.shadowDOM.querySelector('.menu__toggler')
    const menu = this.shadowDOM.querySelector('.menu')
    toggler.addEventListener('click', () => {
      toggler.classList.toggle('active')
      menu.classList.toggle('active')
    })
  }
}

customElements.define('nav-bar', NavBar)
