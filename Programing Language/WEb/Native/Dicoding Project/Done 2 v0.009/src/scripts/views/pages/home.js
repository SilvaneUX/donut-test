import RestoApiSource from '../../data/dicodingrestoapi-source'
import { createRestoItemTemplate } from '../templates/template-creator'

const Home = {
  async render () {
    return `
        <jumbo-tron id="jumbo-tron">jumbo</jumbo-tron>
          <h1>Resto List</h1>
          <div id="list"></div>
        `
  },

  async afterRender () {
    const resto = await RestoApiSource.restaurantList()
    console.log(resto)
    const restoContainer = document.querySelector('#list')
    resto.forEach((resto) => {
      restoContainer.innerHTML += createRestoItemTemplate(resto)
    })
  }
}
export default Home
