import UrlParser from '../../routes/url-parser';
import YoungHealthSource from '../../data/younghealth-source';
import { createDetailObatTemplate } from '../templates/template-creator';


const DetailObat = {
  async render() {
    return `
    <section class="detail-obat">
        <div class="container-detail-obat">
          <div class="row" id="info-detail-obat">
              
          </div>
        </div>
    </section>
    `;
  },

  async afterRender() {
    const url = UrlParser.parseActiveUrlWithoutCombiner();
    const obat = await YoungHealthSource.detailObat(url.id);
    console.log(obat);

    const detailContainer = document.querySelector('#info-detail-obat');

    detailContainer.innerHTML = createDetailObatTemplate(obat);
  },
};

export default DetailObat;
