import API_ENDPOINT from '../global/api-endpoint'

class RestoApiSource {
  static async restaurantList () {
    const response = await fetch(API_ENDPOINT.LIST)
    const responseJson = await response.json()
    const resto = responseJson.restaurants
    return resto
  }

  static async favoriteResto () {
    const response = await fetch(API_ENDPOINT.FAVORITE)
    const responseJson = await response.json()
    return responseJson.results
  }

  static async detailResto (id) {
    const response = await fetch(API_ENDPOINT.DETAIL(id))
    const responseJson = response.json()
    console.log(responseJson)
    return responseJson
  }
}

export default RestoApiSource
