import CONFIG from '../../global/config'

const createRestoDetailTemplate = (resto) => `
<div class="resto-detail">
    
    <br>
    <h1><a href="/#/detail/${resto.restaurant.id}">${resto.restaurant.name}</a></h1>
    <br>
    <img loading="lazy" tabindex="0" class="lazyload" data-src="${CONFIG.BASE_IMAGE_URL}/${resto.restaurant.pictureId}" title="${resto.restaurant.name}" alt="${resto.restaurant.name}">
    <tb>
        <h5><p>${resto.restaurant.city}</p></h5>
        <h5><p>${resto.restaurant.rating} / 5</p></h5>
        <h5><p>${resto.restaurant.address}</p></h5>
        <h5><p>${resto.restaurant.categories.map(category => category.name).join(', ')} </p></h5>
    </tb>
</div>
<div class="resto-desc">
    <p>${resto.restaurant.description}</p>
</div>
<h1>Menu</h1>
<div class="resto-menu-header">
    <h1>Foods : </h1>
    <h1>Drinks : </h1>
</div>
<div class="resto-menu-items" id="menu-container">
  <div id="foods-container">${resto.restaurant.menus.foods.map(food => `
  <div class="food-item">${food.name}</div>
`).join('')}</div>
  <div id="drinks-container">${resto.restaurant.menus.drinks.map(drink => `
  <div class="drink-item">${drink.name}</div>
`).join('')}</div>
</div>

<div class="resto-review">
    <h1>Review Resto</h1>
    <p>${resto.restaurant.customerReviews.map(customerReviews => `
    <div class="customer-review">
    <h1 class="review-text">" ${customerReviews.review} "</h1>
    <h2 class="review-name">${customerReviews.name} - ${customerReviews.date}</h2>
  </div>
`).join(' ')}</p>
  </div>
`

const createRestoItemTemplate = (resto) => `
<div loading="lazy" class="resto-card lazyload" style="background-image: url(${CONFIG.BASE_IMAGE_URL}/${
  resto.pictureId
});" title="${resto.name}" alt="${resto.name}">

    <br>
    <h1><a href="/#/detail/${resto.id}">${resto.name}</a></h1>
    <br>
    <span>City : <br>${resto.city}</span>
    <span>Rating : <br>${resto.rating} / 5</span>
    <p></p>
    <p>${resto.description.slice(0, 300)} ... </p>
</div>
`

const createLikeButtonTemplate = () => `
  <button aria-label="like this resto" id="likeButton" class="like">
     <i class="fa fa-heart-o" aria-hidden="true"></i>
  </button>
`

const createLikedButtonTemplate = () => `
  <button aria-label="unlike this resto" id="likeButton" class="like">
    <i class="fa fa-heart" aria-hidden="true"></i>
  </button>
`

export {
  createRestoItemTemplate,
  createRestoDetailTemplate,
  createLikeButtonTemplate,
  createLikedButtonTemplate

}
