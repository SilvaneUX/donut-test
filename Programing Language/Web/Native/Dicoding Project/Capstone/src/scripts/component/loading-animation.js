class LoadingAnimation extends HTMLElement {
  connectedCallback() {
    this.classList.add('loading');
    this.render();
  }

  render() {
    this.innerHTML = `
    <div class="loader loadingio-spinner-rolling-aiak6voamqs">
      <div class="ldio-xy82pdw42sf">
        <div>
        </div>
      </div>
    </div>
    `;
  }
}

customElements.define('loading-animation', LoadingAnimation);
