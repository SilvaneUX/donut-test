const assert = require('assert')
const { async } = require('regenerator-runtime')

Feature('Open Detail')

Before(({ I }) => {
  I.amOnPage('#/home')
})

Scenario('match home and detail name', async ({ I }) => {
  I.waitForElement('.resto-card h1 a', 10)
  I.seeElement('.resto-card h1  a')

  const homeResto = locate('.resto-card h1 a').first()
  const homeRestoName = await I.grabTextFrom(homeResto)
  I.click(homeResto)

  I.seeElement('#list')
  I.seeElement('.resto-detail h1 a')
  const detailResto = locate('.resto-detail h1 a').first()
  const detailRestoName = await I.grabTextFrom(detailResto)

  assert.strictEqual(homeRestoName, detailRestoName)
})
