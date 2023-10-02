import CONFIG from '../../globals/config';

const createArtikelTemplate =  (healthy) => 
`
<article class="post-item" >
<img tabindex = 0 class="lazyload thumbnail" data-src="${healthy.image_url}" alt="${healthy.title}">
<div class="post-item-body">
    <h5 class="card-title">${healthy.title}</h5>
    <p class="card-text">${healthy.headline}</p>
  </p>
</div>
</article>

`;
const createMedicineTemplate =  (healthy) => {
  const rupiah = (number)=>{
    return new Intl.NumberFormat("id-ID", {
      style: "currency",
      currency: "IDR"
    }).format(number);
  }

  const price = rupiah(healthy.base_price)

  return `
  <article class="post-item" >
  <img tabindex = 0 class="lazyload thumbnail" data-src="${healthy.image_url}" alt="${healthy.title}">
  <div class="post-item-body">
      <h5 class="card-title">${healthy.name}</h5>
      <p class="card-text">${price}</p>
      <div class="d-grid gap-2 col-6 mx-auto">
          <a href="./#/detail/${healthy.slug}" class="button container-detail">detail</a>
      </div>
  </div>
  </article>
  
  `

}

const createArtikelHome = (healthy) => `
<div class="row g-0 bg-light position-relative">
  <div class="col-md-6 mb-md-0 p-md-4">
    <img src="${healthy.image_url}" class="lazyload w-100" alt="${healthy.title}">
  </div>
  <div class="col-md-6 p-4 ps-md-0">
    <h5 class="mt-0">${healthy.title}</h5>
    <p>${healthy.headline}</p>
    <a href="${healthy.source_url}" class="button ">Selengkapnya</a>
  </div>
</div>
`;

const createrekomenartikeltemplate = (healthy) => `
    <div class="container-rekomendasi">
      <div class="image-rekomendasi">
      <img src="${healthy.image_url ? healthy.image_url : 'images/default-pic.jpg'}" class="image-rekomendasi" alt="${healthy.title}">
      </div>
      <div class="info-rekomendasi">
        <h4>${healthy.title}</h4>
        <p class="headline"> ${healthy.headline}....</p>
        <p class="selengkapnya">
        <a href="${healthy.source_url}" >Selengkapnya</a>
        </p>      
      </div>
    </div>
`;

const createDetailObatTemplate = (healthy) => `
    <div class="col-md-6">
      <img src="${healthy.image_url ? healthy.image_url : 'images/default-pic.jpg'}" class="image-detail-obat" alt="${healthy.canon_slug}">
      <p>${healthy.bpom_number}</p>             
    </div>
    <div class="col-md-6 deskripsi-detail-obat">
      <h3>${healthy.canon_slug}</h3>
      <h4 class="base-price">Rp.${healthy.base_price} <span class="perstrip">${healthy.selling_unit}</span></h4>
      <p>Deskripsi : <br>
      ${healthy.description}
      </p>
      <p> Dosis : <br>
      ${healthy.dosage}
      </p>
      <p> Cara Pemkaian : <br>
      ${healthy.how_to_use}
      </p>
      <p> Effect Samping : <br>
      ${healthy.side_effects}
      </p>
      <p> Packaging : <br>
      ${healthy.packaging}
      </p>
      <p class="warning-obat">${healthy.warning}</p>

    </div>

`;

const createAboutWebTemplate = () => `
<div class="row d-flex align-items-center wrap-about">
  <div class="col-lg-5 gambar-about">
    <img class="img-baner1 lazyload" data-src="./images/Baner1.jpg"  alt="Tentang Aplikasi" tabindex="0">
    </div>
    <div class="col-lg-3 text-about">
      <h2 class="heading-1" tabindex="0">Mengenal Website Young Healty.</h2>
      <p tabindex="0">
      Situs web ini bertujuan untuk memberikan informasi yang berguna dan terpercaya 
      tentang kesehatan dan gaya hidup sehat. Kami menyediakan berbagai artikel dan 
      sumber daya yang berkaitan dengan topik-topik kesehatan, kami juga menyediakan kalkulator BMI
      untuk mengukur proporsi berat badan seseorang berdasarkan tinggi badan mereka. BMI adalah perbandingan 
      antara berat badan dengan kuadrat tinggi badan seseorang. Kalkulator BMI memberikan estimasi apakah 
      berat badan seseorang berada dalam kisaran yang sehat atau tidak. Ditambah dengan rekomendasi artikel 
      yang dapat membuatmu lebih sehat. 
      </p>
    </div>
  </div>
`;

const createFiturWebTemplate = () => `
  <h2 class="heading-2" tabindex="0">Fitur yang Ada Dalam Website </h2>
  <div class="col-12 col-md-10 mx-auto d-flex flex-column flex-md-row fitur-card">
    <div class="col-12 col-md-4 mb-4 container-fitur">
      <div class="card h-100 border-0 text-center">
        <div class="logo-fitur d-flex justify-content-center align-items-center mx-auto">
          <i class="fas fa-capsules fa-7x" style="color: #e6b60a;"></i>
        </div>
        <div class="card-body body-fitur">
          <h3 class="card-title heading-3" tabindex="0">Informasi Obat-Obatan</h3>
          <p class="card-text" tabindex="0">Dapat mengetahui Informasi tentang harga obat-obatan terkini.</p>
        </div>
      </div>
    </div>
    <div class="col-12 col-md-4 mb-4 container-fitur">
      <div class="card h-100 border-0 text-center">
        <div class="logo-fitur d-flex justify-content-center align-items-center mx-auto">
        <i class="fas fa-calculator fa-7x" style="color: #e6b60a;"></i>
        </div>
        <div class="card-body body-fitur">
          <h3 class="card-title heading-3" tabindex="0">Kalkulator BMI</h3>
          <p class="card-text" tabindex="0">Melakukan perhitungan untuk mengukur proporsi berat badan seseorang berdasarkan tinggi badan mereka. BMI adalah perbandingan antara berat badan dengan kuadrat tinggi badan seseorang. Kalkulator BMI memberikan estimasi apakah berat badan seseorang berada dalam kisaran yang sehat atau tidak. Ditambah dengan rekomendasi artikel yang dapat membuatmu lebih sehat.</p>
        </div>
      </div>
    </div>
    <div class="col-12 col-md-4 container-fitur">
      <div class="card h-100 border-0 text-center">
        <div class="logo-fitur d-flex justify-content-center align-items-center mx-auto">
        <i class="fas fa-book fa-7x" style="color: #e6b60a;"></i>
        </div>
        <div class="card-body body-fitur">
          <h3 class="card-title heading-3" tabindex="0">Artikel Edukasi Kesehatan</h3>
          <p class="card-text" tabindex="0">Berisi artikel-artikel kesehatan terkini dan dapat membantu masalah anda. menggunakan api hallodoc yang pastinya terupdate dimasa kini</p>
        </div>
      </div>
    </div>
  </div>
`;

const createTeamPengembangTemplate = () => `
  <h2 class="heading-4" tabindex="0">Team Pengembang Website</h2>

  <div class="row mb-0 mb-lg-4 justify-content-center">
      <div class="col-lg-3 mb-4 mb-lg-0">
        <div class="card cardBx card-hover-img overflow-hidden shadow">
          <img class="img-profile card-img-top lazyload" data-src="./images/Adian.jpeg"  alt="Adian Ali Pratama" tabindex="0">
          <div class="card-body card-hover position-absolute w-100">
            <h5 class="card-title">Adian Ali Pratama</h5>
            <p>F013XB249</p>
            <a href="https://www.instagram.com/adianali_/"><i class="fa fa-camera-retro fa-2x" style="margin-top: 5px;"></i></a>
            <a href="https://github.com/adianali"><i class="fab fa-github-square fa-2x" style="margin-left: 40px;"></i></a>
            <a href="https://www.linkedin.com/in/adian-ali-pratama-987a4b265/"> <i class="fab fa-linkedin-in fa-2x" style="margin-left: 40px;"></i></a>
          </div>
        </div>
      </div>
      <div class="col-lg-3 mb-4 mb-lg-0">
        <div class="card cardBx card-hover-img overflow-hidden shadow">
        <img class="img-profile card-img-top lazyload" data-src="./images/marsya.jpg"  alt="Marsya Farras Nabilah" tabindex="0">
          <div class="card-body card-hover position-absolute w-100">
            <h5 class="card-title">Marsya Farras Nabilah</h5>
            <p>F013YB372</p>
            <a href="https://www.instagram.com/marsyafrrs/"><i class="fa fa-camera-retro fa-2x" style="margin-top: 5px;"></i></a>
            <a href="https://github.com/Marsyafrrs"><i class="fab fa-github-square fa-2x" style="margin-left: 40px;"></i></a>
            <a href="https://www.linkedin.com/in/marsya-farras-nabilah-a6a287262"> <i class="fab fa-linkedin-in fa-2x" style="margin-left: 40px;"></i></a>
          </div>
        </div>
      </div>
    </div>
    
    <div class="row mb-0 mb-lg-4 justify-content-center">
      <div class="col-lg-3 mb-4 mb-lg-0">
        <div class="card cardBx card-hover-img overflow-hidden shadow">
        <img class="img-profile card-img-top lazyload" data-src="./images/dika.jpg"  alt="Muhamad Andika Try Satria" tabindex="0">
          <div class="card-body card-hover position-absolute w-100">
            <h5 class="card-title">Muhammad Andika Try Satria</h5>
            <p>F137XB315</p>
            <a href="https://www.instagram.com/dikasatriyaa/"><i class="fa fa-camera-retro fa-2x" style="margin-top: 5px;"></i></a>
            <a href="https://github.com/dikasatriyaa/"><i class="fab fa-github-square fa-2x" style="margin-left: 40px;"></i></a>
            <a href="https://www.linkedin.com/in/muhamad-andika-try-satria-767bb5152/"> <i class="fab fa-linkedin-in fa-2x" style="margin-left: 40px;"></i></a>
          </div>
        </div>
      </div>
      <div class="col-lg-3 mb-4 mb-lg-0">
        <div class="card cardBx card-hover-img overflow-hidden shadow">
        <img class="img-profile card-img-top lazyload" data-src="./images/silvanus.jpg"  alt="Silvanus Prihantono" tabindex="0">
          <div class="card-body card-hover position-absolute w-100">
            <h5 class="card-title">Silvanus Prihantono</h5>
            <p>F015XB472</p>
            <a href="https://www.instagram.com/_silvanus_/"><i class="fa fa-camera-retro fa-2x" style="margin-top: 5px;"></i></a>
            <a href="https://github.com/SilvaneUX"><i class="fab fa-github-square fa-2x" style="margin-left: 40px;"></i></a>
            <a href="https://linkedin.com/in/sux"> <i class="fab fa-linkedin-in fa-2x" style="margin-left: 40px;"></i></a>
          </div>
        </div>
      </div>
    </div>
`;


export {
  createArtikelTemplate,
  createArtikelHome,
  createMedicineTemplate,
  createrekomenartikeltemplate,
  createDetailObatTemplate,
  createAboutWebTemplate,
  createFiturWebTemplate,
  createTeamPengembangTemplate,
};
