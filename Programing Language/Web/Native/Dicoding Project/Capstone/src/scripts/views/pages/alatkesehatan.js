import { createrekomenartikeltemplate } from '../templates/template-creator';
import TheRestaurantSource from '../../data/younghealth-source';

const AlatKesehatan = {
  async render() {
    return `
      <section class="content-kalkulator-bmi">
      <div class="container " style="width:40%">
        <div class="card mx-auto post-item" style="margin-top:100px">
        <h5 class="card-title text-center mt-4">Kalkulator BMI (IMT)</h5>
        <div class="card-body">
                <div class="mb-3">
                  <label for="jenis-kelamin" class="form-label">Apa Jenis Kelamin Kamu? </label>
                </div>
                <div class="d-grid gap-2 d-md-flex justify-content-md-center" aria-label="Basic radio toggle button group">
                  <input type="radio" class="btn-check" name="btnradio" id="btnradio1" autocomplete="off" checked>
                  <label class="btn btn-outline-primary" for="btnradio1">                <svg xmlns="http://www.w3.org/2000/svg" width="21" height="20" fill="none" viewBox="0 0 21 20"><g clip-path="url(#hhg-gen-id1)"><path fill="#45A4FF" d="M11.203 7.633l1.914 1.914 6.397-6.397L17.6 1.235l-6.397 6.398z"></path><path fill="#45A4FF" d="M8.083 5.334a7.333 7.333 0 100 14.667 7.333 7.333 0 000-14.667zm0 11.96a4.626 4.626 0 110-9.253 4.626 4.626 0 010 9.252z"></path><path fill="#2D87F3" d="M7.508 8.077a4.626 4.626 0 100 9.181 4.627 4.627 0 010-9.181zM8.083 5.334a7.43 7.43 0 00-.575.022 7.334 7.334 0 010 14.622 7.333 7.333 0 10.575-14.644zM19.88 2.785v-.78L18.744.872h-.78l-2.707 2.707h1.55c.2 0 .364.163.364.365v1.55l2.707-2.708z"></path><path fill="#45A4FF" d="M18.043 0h-4.585a.365.365 0 00-.364.365v1.978c0 .201.163.364.364.364h4.22c.201 0 .365.163.365.365v4.22c0 .2.163.364.364.364h1.978a.365.365 0 00.365-.364V.365A.365.365 0 0020.385 0h-2.342z"></path></g><defs><clipPath id="hhg-gen-id1"><path fill="#fff" d="M0 0H20V20H0z" transform="translate(.75)"></path></clipPath></defs></svg>  Laki-laki</label>

                  <input type="radio" class="btn-check" name="btnradio" id="btnradio2" autocomplete="off">
                  <label class="btn btn-outline-primary" for="btnradio2">                <svg xmlns="http://www.w3.org/2000/svg" width="21" height="20" fill="none" viewBox="0 0 21 20"><path fill="#FE9DC2" d="M13.748 15.546h-1.503a.321.321 0 01-.321-.322v-3.7H9.577v3.7a.321.321 0 01-.322.322H7.753a.321.321 0 00-.321.321v1.704c0 .178.144.322.321.322h1.502c.178 0 .322.144.322.321v1.465c0 .178.144.321.321.321h1.704a.321.321 0 00.322-.321v-1.465c0-.177.144-.321.321-.321h1.503a.321.321 0 00.321-.322v-1.704a.322.322 0 00-.321-.321z"></path><path fill="#FC488D" d="M9.576 11.523v2.151a7.466 7.466 0 002.347 0v-2.15H9.576z"></path><path fill="#FE9DC2" d="M10.75 0a6.357 6.357 0 100 12.715A6.357 6.357 0 0010.75 0zm0 10.368a4.01 4.01 0 110-8.021 4.01 4.01 0 010 8.021z"></path><path fill="#FC488D" d="M10.157 2.391a4.01 4.01 0 100 7.934 4.011 4.011 0 010-7.934zM10.75 0c-.2 0-.398.01-.593.028a6.358 6.358 0 010 12.66A6.357 6.357 0 1010.75 0z"></path></svg>  Perempuan</label>
              </div>
              <div class="mb-3 mt-3">
                  <label for="berat-badan" class="form-label">Berapa Berat Badan Kamu ? (kg) </label>
                  <input type="number" class="form-control" id="bb" placeholder="Berat Badan">
              </div>
              <div class="mb-3">
                  <label for="tinggi-badan" class="form-label">Berapa Tinggi Kamu ? (cm) </label>
                  <input type="number" class="form-control" id="tt" placeholder="Tinggi Badan">
              </div>
              <div class="mb-3">
                  <label for="tinggi-badan" class="form-label">Berapa Umur Kamu ? (tahun) </label>
                  <input type="number" class="form-control" id="umur" placeholder="Tinggi Badan">
              </div>
            </div>
              <button id="bmiSubmit" type="submit" class="btn button mx-auto mb-4">Hitung</button>
            </div>
      </div>

        <div class="result">
          <p>Hasil BMI Anda</p>
          <div id="result">00.00</div>
          <p class="comment-result"></p>
        </div>

        <div id="Modal" class="modal">
          <div class="modal-content">
            <span class="close">&times;</span>
            <p id="modalText"></p>
          </div>
        </div>

        <div class="rekomendasi-artikel">
          <p class="header-rekomendasi">Baca artikel untuk lebih memahami BMI mu</p>
        </div>
      </section>
    `;
  },

  async afterRender() {
    document.title = 'Alat Kesehatan - Young Health';

    const umur = document.getElementById("umur");
    const tinggi = document.getElementById("tt");
    const berat = document.getElementById("bb");
    const resultArea = document.querySelector(".comment-result");
    const modal = document.getElementById("Modal");
    const span = document.getElementsByClassName("close")[0];
    const submitButton = document.getElementById("bmiSubmit");
    const rekomendasiartikel = document.querySelector(".rekomendasi-artikel");
    const headerrekomendasi = document.querySelector(".header-rekomendasi");
    const healthPost = await TheRestaurantSource.Rekomendasi();
    const healthPostArray = Object.values(healthPost);
    

    submitButton.addEventListener("click", function () {
        countBmi();
    });

    function countBmi() {
      const p = [umur.value, tinggi.value, berat.value];

      const bmi = Number(p[2]) / (Number(p[1]) / 100 * Number(p[1]) / 100);

      let result = "";
      if (bmi < 18.5) {
        result = "Underweight";
      } else if (18.5 <= bmi && bmi <= 24.9) {
        result = "Healthy";
      } else if (25 <= bmi && bmi <= 29.9) {
        result = "Overweight";
      } else if (30 <= bmi && bmi <= 34.9) {
        result = "Obese";
      } else if (35 <= bmi) {
        result = "Extremely obese";
      }

      headerrekomendasi.style.display = "block";
      resultArea.style.display = "block";
      document.querySelector(".comment-result").innerHTML = `You are <span id="comment-result"">${result}</span>`;
      document.querySelector("#result").innerHTML = bmi.toFixed(2);

      const firstArray = healthPostArray[0];
      firstArray.forEach((healhty) => {
        rekomendasiartikel.innerHTML += createrekomenartikeltemplate(healhty);
      });
    }

    span.onclick = function () {
      modal.style.display = "none";
    };

    window.onclick = function (event) {
      if (event.target == modal) {
        modal.style.display = "none";
      }
    };
  },
};

export default AlatKesehatan;
