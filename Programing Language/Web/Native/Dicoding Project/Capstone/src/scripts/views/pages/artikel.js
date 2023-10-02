import {createArtikelTemplate} from "../templates/template-creator"
import YoungHealthSource from '../../data/younghealth-source';

const Artikel = {
  async render() {
    return `
    <div class="container">
      <div class="" id="post">
        `;
  },

  async afterRender() {
    document.title = 'Artikel - Young Health';

    const healthPost = await YoungHealthSource.PageHome();
    const healthContainer = document.querySelector('#post');
    healthPost.forEach((healhty) => {
      healthContainer.innerHTML += createArtikelTemplate(healhty);
    })
  },
};

export default Artikel;
