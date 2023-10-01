class FooTer extends HTMLElement {
  constructor () {
    super()
    this.shadowDOM = this.attachShadow({ mode: 'open' })
  }

  connectedCallback () {
    this.render()
  }

  render () {
    this.shadowDOM.innerHTML = `
    <style>
    heatler{
        color: #FFA559;
        transition: color .4s ease;
    }

    heatler:hover{
        color: #44bae8;
    }

    foo-ter{
        position: relatives;
        bottom: 0;
        left: 0;
        right: 0;
        background: #111;
        height: auto;
        width: 100%;
        padding-top: 2em;
        color: #fff;
    }
    
    .foo-ter-bottom{
        background: #000;
        padding: 2em;
        padding-bottom: 1em;
        text-align: center;
    }
    .foo-ter-bottom p{
        font-size: 1.3rem;
        word-spacing: 1em;
        text-transform: capitalize;
        text-align: center;
    }
    .foo-ter-bottom p a{
      color:#44bae8;
      text-decoration: none;
      transition: color .4s ease;
      padding: 45px 0;
    }

    .foo-ter-bottom p a:hover{
        color: #FFA559;
    }
    .foo-ter-bottom span{
        text-transform: uppercase;
        opacity: .4;
        font-weight: 200;
    }
    .foo-ter-menu{
        display: flex;
        align-items: center;
        justify-content: center;
    }
    .foo-ter-menu ul{
      display: flex;
    }
    .foo-ter-menu ul li{
    
    display: block;
    }
    .foo-ter-menu ul li a{
      padding: 1rem ;
      color: #cfd2d6;
      text-decoration: none;
    }
    .foo-ter-menu ul li a:hover{
      color: #27bcda;
    }
    
    @media (max-width:600px) {
      *{
        word-spacing: 0.1em;
      }
      p{
        font-size: 0.5em;
        padding: 40px
      }

      foo-ter{
        padding-top: 0.5em;
        color: #fff;
    }
    
      .foo-ter-bottom{
        background: #000;
        padding: 0.1em;
        padding-bottom: 1em;
        text-align: center;
    }
      .foo-ter-bottom p{
        font-size: 0.7rem;
        word-spacing: 2em;
        text-transform: capitalize;
    }
    .foo-ter-bottom p a{
      padding: auto;
    }
    }
    
    
    </style>
    

    
    <div class="foo-ter-bottom">
    
                <div class="foo-ter-menu">
                  <ul class="f-menu">
                    <li><a href="index.html">Home</a></li>
                    <li><a href="#">Favorite</a></li>
                    <li><a href="https://cutt.ly/sux">About ME</a></li>
                  </ul>
                </div>
                <p>copyright &copy; <heatler>H-EAT-Ler</heatler> by <a href="https://cutt.ly/sux">SilvaneUX</a>  </p>
    </div>


        `
  }
}

customElements.define('foo-ter', FooTer)
