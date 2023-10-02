import {createMedicineTemplate} from "../templates/template-creator"
import YoungHealthSource from "../../data/younghealth-source";

const Medicine = {
  async render() {
    return `
    <div class="container">
      <div class="" id="medicine">
        `;
  },

  async afterRender() {
    document.title = 'Obat obatan - Young Health';

    const healthPosts = await YoungHealthSource.Obat();
    const healthContainer = document.querySelector('#medicine');
    healthPosts.forEach((healhty) => {
      healthContainer.innerHTML += createMedicineTemplate(healhty);
    })
  },
};

export default Medicine;
