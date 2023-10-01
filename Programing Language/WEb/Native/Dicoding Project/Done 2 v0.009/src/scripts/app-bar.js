class AppBar extends HTMLElement {
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
          
          padding: 0;
          box-sizing: border-box;
        
          
        }
        :host {
          display: block;
          width: 100%;
          background-color: #FFA559;
          color: white;
          box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
          border-radius: 15px 15px 50px 50px;
          text-align: center;
          
         
        }
        h2 {
          color: #323232;
          padding: 16px;
        }
      </style>
      
      <h2>H-EAT-Ler</h2>
    `
  }
}

customElements.define('app-bar', AppBar)
