class ContactUs extends HTMLElement {
    connectedCallback() {
      this.render();
    }
  
    render() {
      this.innerHTML = `
      <section class="kontak">
          <div class="container py-5" >
              <div class="row" >
                  <div class="col-lg-6 mx-auto">
                      <div class="card">
                          <div class="card-body">
                              <div class="row">
                                  <div class="col-lg-12">
                                      <div class="head text-center text-white py-3">
                                          <h3>Contact Us</h3>                
                                      </div>
                                  </div>
                              </div>
                              <div class="form p-3">
                                  <div class="form-row my-4">
                                      <div class="col-lg-12">
                                          <input type="text" name="nama" class="effect-1" placeholder="Name" required>
                                      </div>
                                  </div>
                                  <div class="form-row pb-4">
                                      <div class="col-lg-12">
                                          <input type="text" name="telp" class="effect-1" placeholder="NO HP" required>
                                      </div>
                                  </div>
                                  <div class="form-row pb-4">
                                      <div class="col-lg-12">
                                          <input type="text" name="email" class="effect-1" placeholder="Email Addres" required>
                                      </div>
                                  </div>
                                  <div class="form-row pt-5">
                                      <div class="col-lg-12">
                                      <textarea name="pesan" class="effect-1" placeholder="Your Message"></textarea>
                                      </div>
                                  </div>
                                  <div class="form-row pt-4">
                                      <div class="col-lg-6">
  
                                      </div>
                                      <div class="col-lg-2">
                                      <input type="submit" name="submit" value="SEND MESSAGE" class="btn1">
                                      </div>
                                  </div>
                              </div>
                          </div>
                      </div>
                  </div>
              </div>
          </div>

       
      </section>
        `;
    }
  }
  
  customElements.define('contact-us', ContactUs);