import UrlParser from '../../routes/url-parser'
import RestoApiSource from '../../data/dicodingrestoapi-source'
import { createRestoDetailTemplate } from '../templates/template-creator'
import LikeButtonPresenter from '../../utils/like-button-presenter'
import FavoriteRestoIdb from '../../data/favorite-resto-idb'

const Detail = {
  async render () {
    return `
        <h1>Detail Resto</h1>
        <div class="like-container">
          <div class="fav-header">Do you</div>
          <div id="likeButtonContainer"></div>
          <div class="fav-header">this resto?</div>
        </div>
        
        <div id="list"></div>
        <div id="review"></div>
        
      `
  },

  async afterRender () {
    const url = UrlParser.parseActiveUrlWithoutCombiner()
    const resto = await RestoApiSource.detailResto(url.id)
    console.log(resto)
    const restoContainer = document.querySelector('#list')
    restoContainer.innerHTML = createRestoDetailTemplate(resto)

    LikeButtonPresenter.init({
      likeButtonContainer: document.querySelector('#likeButtonContainer'),
      favoriteResto: FavoriteRestoIdb,
      resto: {
        id: resto.restaurant.id,
        name: resto.restaurant.name,
        pictureId: resto.restaurant.pictureId,
        city: resto.restaurant.city,
        rating: resto.restaurant.rating,
        description: resto.restaurant.description
      }
    })
  }
}

export default Detail
