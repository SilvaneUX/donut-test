const assert = require('assert');

Feature('Liking Resto');
 
Scenario('showing empty liked movies', async ({ I }) => {

  I.amOnPage('/');
  pause();
  I.seeElement('.name a');
  const firstResto = locate('.name a').first();
  const firstRestoTitle = await I.grabTextFrom(firstResto);
  I.click(firstResto);

  I.seeElement('#likeButton');
  I.click('#likeButton');

  I.amOnPage('/#/favorite');
  I.seeElement('.favorite-item');

  const likedRestoTitle = await I.grabTextFrom('.name');
  assert.strictEqual(firstRestoTitle, likedRestoTitle);
});