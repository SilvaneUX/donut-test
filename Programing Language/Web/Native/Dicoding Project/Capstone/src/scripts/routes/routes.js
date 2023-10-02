import Home from '../views/pages/home';
import Artikel from '../views/pages/artikel';
import AlatKesehatan from '../views/pages/alatkesehatan';
import Medicine from '../views/pages/medicine';
import Contact from '../views/pages/contact';
import AboutUs from '../views/pages/about-us';
import DetailObat from '../views/pages/detail-obat';

const routes = {
  '/': Home, //default routes
  '/home': Home, 
  '/artikel': Artikel,
  '/obat' : Medicine,
  '/imt': AlatKesehatan,
  '/contact-us' : Contact,
  '/about-us' : AboutUs,
  '/detail/:slug' : DetailObat,
  
};

export default routes;
