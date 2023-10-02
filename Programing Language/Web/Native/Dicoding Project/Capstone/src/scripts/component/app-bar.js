class AppBar extends HTMLElement {
  connectedCallback() {
    this.render();
  }

  render() {


    this.innerHTML = `
    <nav class="navbar navbar-expand-lg  navbar-ligth fixed-top shadow-5-strong animate__animated animate__fadeInDown">
    <div class="container">
      <a class="navbar-brand" href="#/home" id="brand">Young<b>Health</b></a>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarNavDropdown">
        <ul class="navbar-nav ms-auto">
          <li class="nav-item">
            <a class="nav-link active" aria-current="page" href="#/home">Home</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/artikel">Artikel</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/obat">Obat-obatan</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/imt">Hitung IMT</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/about-us">About Us</a>
          </li>
          <li class="nav-item">
              <a class="nav-link" href="#/contact-us">Contact Us</a>
          </li>
        </ul>
      </div>
    </div>
  </nav>
  <div class="header-menu" id="menu"></div>
      `;
  }
}

customElements.define('app-bar', AppBar);