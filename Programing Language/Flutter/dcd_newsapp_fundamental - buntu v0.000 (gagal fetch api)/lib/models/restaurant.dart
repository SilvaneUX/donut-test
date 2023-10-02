// list resto

class RestaurantList {
  final bool error;
  final String message;
  final int count;
  final List<Restaurant> restaurants;

  RestaurantList({
    required this.error,
    required this.message,
    required this.count,
    required this.restaurants,
  });

  factory RestaurantList.fromJson(Map<String, dynamic> json) {
    final restaurantList = json['restaurants'] as List;
    final restaurants = restaurantList.map((json) => Restaurant.fromJson(json)).toList();

    return RestaurantList(
      error: json['error'],
      message: json['message'],
      count: json['count'],
      restaurants: restaurants,
    );
  }
}




//detail resto

class Restaurant {
  final String id;
  final String name;
  final String description;
  final String city;
  final String pictureId;
  final double rating;
  final List<Food> foods;
  final List<Drink> drinks;
  final Menus menus;

// API endpoints
  static const String baseUrl = 'https://restaurant-api.dicoding.dev';
  static const String listEndpoint = '/list';
  static const String detailEndpoint = '/detail';
  static const String searchEndpoint = '/search';

  String getLargeImageUrl() {
    return '$baseUrl/images/large/$pictureId';
  }


  Restaurant({
    required this.id,
    required this.name,
    required this.description,
    required this.city,
    required this.pictureId,
    required this.rating,
    required this.foods,
    required this.drinks,
    required this.menus,
  });

  factory Restaurant.fromJson(Map<String, dynamic> json) {
    print('Parsing JSON data: $json');
    return Restaurant(
      id: json['id'],
      name: json['name'],
      description: json['description'],
      city: json['city'],
      pictureId: json['pictureId'],
        rating: json['rating'] is int ? json['rating'].toDouble() : json['rating'],
      foods: (json['menus']['foods'] as List).map((foodJson) => Food.fromJson(foodJson)).toList(),
      drinks: (json['menus']['drinks'] as List).map((drinkJson) => Drink.fromJson(drinkJson)).toList(),
      menus: Menus.fromJson(json['menus']),
    );
  }
}

class Food {
  final String name;

  Food({required this.name});

  factory Food.fromJson(Map<String, dynamic> json) {
    return Food(name: json['name']);
  }
}

class Drink {
  final String name;

  Drink({required this.name});

  factory Drink.fromJson(Map<String, dynamic> json) {
    return Drink(name: json['name']);
  }
}


class Menus {
  final List<Food> foods;
  final List<Drink> drinks;

  Menus({required this.foods, required this.drinks});

  factory Menus.fromJson(Map<String, dynamic> json) {
    final foodList = json['foods'] as List;
    final drinkList = json['drinks'] as List;

    final foods = foodList.map((json) => Food.fromJson(json)).toList();
    final drinks = drinkList.map((json) => Drink.fromJson(json)).toList();

    return Menus(
      foods: foods,
      drinks: drinks,
    );
  }
}