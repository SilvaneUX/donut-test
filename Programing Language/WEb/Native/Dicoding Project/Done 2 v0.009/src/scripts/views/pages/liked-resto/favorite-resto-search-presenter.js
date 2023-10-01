// class FavoriteRestoearchPresenter {
//   constructor ({ favoriteResto }) {
//     this._listenToSearchRequestByUser()
//     this._favoriteResto = favoriteResto
//   }

//   _listenToSearchRequestByUser () {
//     this._queryElement = document.getElementById('query')
//     this._queryElement.addEventListener('change', (event) => {
//       this._searchRestos(event.target.value)
//     })
//   }

//   async _searchRestos (latestQuery) {
//     this._latestQuery = latestQuery.trim()

//     let foundRestos
//     if (this.latestQuery.length > 0) {
//       foundRestos = await this._favoriteRestos.searchRestos(this.latestQuery)
//     } else {
//       foundRestos = await this._favoriteRestos.getAllRestos()
//     }
//     this._showFoundRestos(foundRestos)
//   }

//   _showFoundRestos (restos) {
//     let html
//     if (restos.length > 0) {
//       html = restos.reduce(
//         (carry, resto) => carry.concat(`<li class="resto"><span class="resto__title">${resto.title || '-'}</span></li>`),
//         ''
//       )
//     } else {
//       html = '<div class="restos__not__found">Film tidak ditemukan</div>'
//     }

//     document.querySelector('.restos').innerHTML = html

//     document.getElementById('resto-search-container')
//       .dispatchEvent(new Event('restos:searched:updated'))
//   }

//   get latestQuery () {
//     return this._latestQuery
//   }
// }

// export default FavoriteRestoearchPresenter
