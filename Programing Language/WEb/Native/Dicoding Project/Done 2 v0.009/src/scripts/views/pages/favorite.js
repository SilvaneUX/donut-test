import FavoriteRestoIdb from '../../data/favorite-resto-idb'
import { createRestoItemTemplate } from '../templates/template-creator'

const Favorite = {
  async render () {
    return `
    <div class="content">
      <h1>Your Favorite Resto</h1>
      <div id="resto" class="resto">
      </div>
    </div>
        
        `
  },

  async afterRender () {
    const resto = await FavoriteRestoIdb.getAllResto()
    const restoContainer = document.querySelector('#resto')

    if (resto.length === 0) {
      restoContainer.innerHTML += '<h2>Tidak Ada Resto Favorit</h2>'
    } else {
      resto.forEach((resto) => {
        restoContainer.innerHTML += createRestoItemTemplate(resto)
      })
    }
  }
}
export default Favorite
