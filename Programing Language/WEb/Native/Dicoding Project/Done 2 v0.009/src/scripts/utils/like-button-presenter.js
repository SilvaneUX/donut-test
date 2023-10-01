import { createLikeButtonTemplate, createLikedButtonTemplate } from '../views/templates/template-creator'

const LikeButtonPresenter = {
  async init ({ likeButtonContainer, favoriteResto, resto }) {
    this._likeButtonContainer = likeButtonContainer
    this._resto = resto
    this._favoriteResto = favoriteResto

    await this._renderButton()
  },

  async _renderButton () {
    const { id } = this._resto

    if (await this._isRestoExist(id)) {
      this._renderLiked()
    } else {
      this._renderLike()
    }
  },

  async _isRestoExist (id) {
    const resto = await this._favoriteResto.getResto(id)
    return !!resto
  },

  _renderLike () {
    this._likeButtonContainer.innerHTML = createLikeButtonTemplate()

    const likeButton = document.querySelector('#likeButton')
    likeButton.addEventListener('click', async () => {
      await this._favoriteResto.putResto(this._resto)
      this._renderButton()
    })
  },

  _renderLiked () {
    this._likeButtonContainer.innerHTML = createLikedButtonTemplate()

    const likeButton = document.querySelector('#likeButton')
    likeButton.addEventListener('click', async () => {
      await this._favoriteResto.deleteResto(this._resto.id)
      this._renderButton()
    })
  }
}

export default LikeButtonPresenter
