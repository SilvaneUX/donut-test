class JumboTron extends HTMLElement {
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
          * {
            padding: auto;
          }
          img {
            display: block;
            max-width: 100%;
            background-color: #FFA559;
            box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
            border-radius: 3em 3em 3em 3em;
            content-align: center;
            color: #323232;
            background-size: auto;
            margin: 1em;
            margin-left: auto;
            margin-right: auto;
          }
  
          h2 {
            padding: 4.5em;
            margin : 1em;
          }
          
          h1 {
            Background-color: #000;
            color: #fff;
            padding: auto;
            margin : auto;
          }

          @media screen and (min-width: 1200px){
            :host{
                min-width: 1000px; 
            }
          }

          @media screen and (max-width: 1199px){
            :host{
                min-width: full-width;; 
            }
          }


        </style>
        <picture>
        <source type="image/jpeg" media="(max-width: 600px)" srcset="./images/hero-image_1-small.jpg">
        <img class="lazyload" loading="lazy" src="./images/hero-image_1-large.jpg" alt="H-EAT-Ler">
      </picture>
        `
  }
}

customElements.define('jumbo-tron', JumboTron)
