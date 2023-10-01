import CONFIG from './config'

const API_ENDPOINT = {
  LIST: `${CONFIG.BASE_URL}/list`,
  DETAIL: (id) => `${CONFIG.BASE_URL}/detail/${id}`
  //   SEARCH: `${CONFIG.BASE_URL}/search?q=${querry}`
}

export default API_ENDPOINT
