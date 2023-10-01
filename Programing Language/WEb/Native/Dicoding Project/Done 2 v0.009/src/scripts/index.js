import 'regenerator-runtime' /* for async await transpile */
import '../styles/style.css'
import '../styles/responsive.css'
// import './app-bar'
import './jumbo-tron'
// import './nav-bar'
// import './resto-item'
import './foo-ter'
import App from './views/apps'
import swRegister from './utils/sw-register'
import 'lazysizes'
import 'lazysizes/plugins/parent-fit/ls.parent-fit'

console.log('Hello Coders! :)')

window.addEventListener('resize', function () {
  'use strict'
  window.location.reload()
})

// /////////// //
const app = new App({
  button: document.querySelector('#hamburgerButton'),
  drawer: document.querySelector('#navigationDrawer'),
  content: document.querySelector('#content')
})

const skipLink = document.querySelector('.skip-content')
const mainContent = document.querySelector('#content')

skipLink.addEventListener('click', event => {
  event.preventDefault()
  mainContent.scrollIntoView({ behavior: 'smooth' })
  skipLink.blur()
})

window.addEventListener('hashchange', () => {
  app.renderPage()
})

window.addEventListener('load', () => {
  app.renderPage()
  swRegister()
})
