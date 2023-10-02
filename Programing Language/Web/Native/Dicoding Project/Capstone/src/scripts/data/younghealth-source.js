import API_ENDPOINT from '../globals/api-endpoint';

class YoungHealthSource {
  static async PageHome() {
    const response = await fetch(API_ENDPOINT.HOME);
    const responseJson = await response.json();
    return responseJson;
  }
  static async Obat() {
    const response = await fetch(API_ENDPOINT.MEDICINE);
    const responseJson = await response.json();
    return responseJson.result;
  }
  static async Rekomendasi() {
    const response = await fetch(API_ENDPOINT.REKOMENDASI);
    const responseJson = await response.json();
    return responseJson;
  }

  static async detailObat(id) {
    const response = await fetch(API_ENDPOINT.DETAIL_MEDICINE(id));
    return response.json();
  }
}

export default YoungHealthSource;
