import Favorite from '../views/pages/favorite'
import Detail from '../views/pages/detail'
import Home from '../views/pages/home'
// import Me from '../views/pages/about-me'

const routes = {
  '/': Home, // default page
  '/home': Home,
  '/favorite': Favorite,
  '/detail/:id': Detail
  // '/me': Me
}

export default routes
