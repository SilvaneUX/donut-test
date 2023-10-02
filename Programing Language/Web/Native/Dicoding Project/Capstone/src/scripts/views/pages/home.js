import TheRestaurantSource from '../../data/younghealth-source';
import { createArtikelHome } from '../templates/template-creator';

const Home = {
  async render() {
    return `
    <div class="container">
      <div class="jumbotron mb-3">
        <div class="row g-0">
          <div class="col-md-6">
            <div class="jumbotron-body">
            <div class="animate__animated animate__fadeInUp">
            <h1><b>Bukan Sekedar Gaya</b></h1>
            <h1><b>Saatnya Hidup</b></h1>
            <h1 style="margin-bottom: 25px"><b>Lebih Sehat</b></h1>
            </div>
              <p>Waktunya ngasih perhatian lebih ke hidup sehat, biar makin kece dan oke.
              Gak cuma gaya, tapi bikin badan sehat dan pikiran segar. Mulai dari 
              pola makan yangg nyambung, rajin olahraga, tidur yang cukup
              dan jauhin diri dari kebiasaan negatif</p>
              <a href="#/artikel" class="btn button"><b>Pusat Kesehatan</b></a>
              </div>
          </div>
          <div class="col-md-6 " id="heroes">
          <source class="lazyload" type="image/webp" srcset="/images/heros/avatar.webp">
          <img class="hero lazyload img-fluid rounded-end" src="/images/heros/avatar.webp"
               alt="Anak Muda Hidup Sehat">
          </picture>
          </div>
        </div>
      </div>
    </div>

    <div class="container text-center" id="quote">
      <div class="quote-header">
        Quote
      </div>
      <div class="quote-body">
        <blockquote class="blockquote mb-0">
          <p>Sehat itu investasi masa depanmu. Jaga kesehatanmu dan nikmati kehidupan sebagai anak muda yang berdaya.</p>
          <footer class="blockquote-footer">From <b>YoungHealth</b> For <b>You</b></footer>
        </blockquote>
      </div>
    </div>

    <div class="container main-artikel">
      <div class="card mb-3">
        <div class="row g-0">
          <div class="col-md-6">
            <div class="card-body title-artikel">
              <h1 class="card-title"><Wajib><b>Enggak Gampang Sakit <br> Mantepin Sistem Imun Kamu Dengan Buah Nanas</b></h1>
              <p class="card-text">Nanas mengandung zat besi, vitamin C, dan enzim bromelain yang mampu dukung kebugaran tubuh. Salah satu manfaat nanas yakni memperkuat otot.</p>
              <p class="card-text"><small class="text-body-secondary">Last updated 3 mins ago</small></p>
            </div>
          </div>
          <div class="col-md-6">
            <img src="https://d1vbn70lmn1nqe.cloudfront.net/prod/wp-content/uploads/2022/05/17041831/X-Alasan-Lidah-Gatal-Setelah-Makan-Nanas.jpg" class="img-fluid rounded-end" alt="...">
          </div>
        </div>
      </div>
    </div>

    <div class="container" id="list-artikel">
    <h1>Artikel</h1>
    <div class="row">
      <div class="col-md-8" id="home-post">

      </div>
      
  </div>

        `;
  },

  async afterRender() {
    document.title = 'Young Health';

    const healthPost = await TheRestaurantSource.PageHome();
    const healthContainer = document.querySelector('#home-post');
    healthPost.forEach((healhty) => {
      healthContainer.innerHTML += createArtikelHome(healhty);
    })
  },
};

export default Home;
