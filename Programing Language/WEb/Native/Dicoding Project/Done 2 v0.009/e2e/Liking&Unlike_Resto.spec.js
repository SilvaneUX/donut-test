const assert = require('assert')
// eslint-disable-next-line no-unused-vars
const { async } = require('regenerator-runtime')

Feature('liking & Unlike Resto')

Before(({ I }) => {
  I.amOnPage('#/favorite')
})

Scenario('showing empty fav resto', ({ I }) => {
  I.seeElement('#resto')
  I.see('Tidak Ada Resto Favorit', '#resto')
})

Scenario('faving one resto', async ({ I }) => {
  I.see('Tidak Ada Resto Favorit', '#resto')

  I.amOnPage('#/')
  I.waitForElement('.resto-card h1 a', 10)
  I.seeElement('.resto-card h1  a')

  const firstResto = locate('.resto-card h1 a').first()
  const firstRestoName = await I.grabTextFrom(firstResto)
  I.click(firstResto)

  I.seeElement('#likeButtonContainer')
  I.click('#likeButtonContainer')

  I.amOnPage('#/favorite')
  I.seeElement('.resto-card')

  const favedRestoName = await I.grabTextFrom('.resto-card h1 a')

  assert.strictEqual(firstRestoName, favedRestoName)
})

Scenario('unfaving one resto', async ({ I }) => {
  I.see('Tidak Ada Resto Favorit', '#resto')

  I.amOnPage('#/')
  I.waitForElement('.resto-card h1 a', 10)
  I.seeElement('.resto-card h1  a')

  const firstResto = locate('.resto-card h1 a').first()
  const firstRestoName = await I.grabTextFrom(firstResto)
  I.click(firstResto)

  I.seeElement('#likeButtonContainer')
  I.click('#likeButtonContainer')

  I.amOnPage('#/favorite')
  I.seeElement('.resto-card')

  const favedRestoName = await I.grabTextFrom('.resto-card h1 a')

  assert.strictEqual(firstRestoName, favedRestoName)

  // unfaving

  I.click(firstResto)
  I.seeElement('#likeButtonContainer')
  I.click('#likeButtonContainer')

  I.amOnPage('#/favorite')
  I.seeElement('#resto')
  I.see('Tidak Ada Resto Favorit', '#resto')
})
