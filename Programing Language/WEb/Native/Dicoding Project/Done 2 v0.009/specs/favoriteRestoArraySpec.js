import { itActsAsFavoriteRestoModel } from './contract/favoriteRestoContract'

let favoriteResto = []

const FavoriteRestoArray = {
  getResto (id) {
    if (!id) {
      return
    }

    return favoriteResto.find((resto) => resto.id === id)
  },

  getAllResto () {
    return favoriteResto
  },

  putResto (resto) {
    // eslint-disable-next-line no-prototype-builtins
    if (!resto.hasOwnProperty('id')) {
      return
    }

    // pastikan id ini belum ada dalam daftar favoriteResto
    if (this.getResto(resto.id)) {
      return
    }

    favoriteResto.push(resto)
  },

  deleteResto (id) {
    // cara boros menghapus resto dengan meng-copy resto yang ada
    // kecuali resto dengan id == id
    favoriteResto = favoriteResto.filter((resto) => resto.id !== id)
  }
}

describe('Favorite Resto Array Contract Test Implementation', () => {
  // eslint-disable-next-line no-return-assign
  afterEach(() => favoriteResto = [])

  itActsAsFavoriteRestoModel(FavoriteRestoArray)
})
