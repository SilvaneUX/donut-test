import CONFIG from './config';

const API_ENDPOINT = {
  HOME: `${CONFIG.BASE_URL}`,
  MEDICINE: `${CONFIG.MEDICINE}`,
  DETAIL_MEDICINE: (slug) => `${CONFIG.DETAIL_MEDICINE}detail/${slug}`,
  REKOMENDASI: `${CONFIG.REKOMENDASI}`,
};

export default API_ENDPOINT;
