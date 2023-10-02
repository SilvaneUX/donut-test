import 'regenerator-runtime';
import 'bootstrap/dist/css/bootstrap.min.css';
import 'bootstrap'
import '../styles/main.css';
import '../styles/responsive.css';
import './component/app-bar';
import App from './views/app';
import swRegister from './utils/sw-register';
import 'lazysizes';
import 'lazysizes/plugins/parent-fit/ls.parent-fit';
import 'animate.css';


const app = new App({
  button: document.querySelector('#menu'),
  drawer: document.querySelector('#drawer'),
  content: document.querySelector('#maincontent'),
});



window.addEventListener('hashchange', () => {
  app.renderPage();
});

window.addEventListener('load', () => {
  app.renderPage();
  swRegister();
});
