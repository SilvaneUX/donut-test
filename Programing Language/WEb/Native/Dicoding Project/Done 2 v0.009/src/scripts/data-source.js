const searchUrl = 'https://restaurant-api.dicoding.dev/list'
class DataSource {
  static listResto () {
    return fetch(`${searchUrl}`)
      .then(response => {
        return response.json()
      })
      .then(responseJson => {
        return Promise.resolve(responseJson.results)
      })
  }
}

export default DataSource
