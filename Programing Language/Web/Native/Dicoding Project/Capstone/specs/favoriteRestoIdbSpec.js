import { itActsAsFavoriteRestoModel } from './contract/favoriteRestoContract';
import FavoriteRestoIdb from '../src/scripts/data/favorite-menu-idb';

describe('Favorite Resto Idb Contract Test Implementation', () => {
  afterEach(async () => {
    (await FavoriteRestoIdb.getAllresto()).forEach(async (resto) => {
      await FavoriteRestoIdb.deleteResto(resto.id);
    });
  });

  itActsAsFavoriteRestoModel(FavoriteRestoIdb);
});
