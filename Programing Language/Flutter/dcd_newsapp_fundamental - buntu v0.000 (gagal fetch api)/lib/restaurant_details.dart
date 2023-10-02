import 'package:flutter/material.dart';
import 'package:dcd_newsapp_fundamental/models/restaurant.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

class RestaurantDetailsPage extends StatelessWidget {
  final Restaurant restaurantId;

  const RestaurantDetailsPage({super.key, required this.restaurantId});

  Future<Restaurant> _loadRestaurantDetails() async {
    final response = await http.get(Uri.parse('https://restaurant-api.dicoding.dev/detail/$restaurantId'));
    if (response.statusCode == 200) {
      final jsonData = json.decode(response.body);
      final restaurant = Restaurant.fromJson(jsonData['restaurant']);
      return restaurant;
    } else {
      throw Exception('Failed to load restaurant details');
    }
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder<Restaurant>(
        future: _loadRestaurantDetails(),
        builder: (BuildContext context, AsyncSnapshot<Restaurant> snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return Center(child: CircularProgressIndicator());
          } else if (snapshot.hasError) {
            return Center(child: Text('Error loading restaurant details.'));
          } else if (!snapshot.hasData) {
            return Center(child: Text('No data available.'));
          }

          final restaurant = snapshot.data!;
          return Scaffold(
            appBar: AppBar(
              title: Text(restaurantId.name),
              centerTitle: true,
            ),
            body: Center(
              child: SingleChildScrollView(
                padding: const EdgeInsets.all(16.0),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: [
                    ClipRRect(
                      borderRadius: BorderRadius.circular(8.0),
                      child: Image.network(
                        restaurant.getLargeImageUrl(),
                        width: 800, // Set the desired width for the image
                        fit: BoxFit.cover,
                      ),
                    ),
                    const SizedBox(height: 16.0),
                    Text(
                      restaurantId.name,
                      style: const TextStyle(fontSize: 24.0, fontWeight: FontWeight.bold),
                    ),
                    const SizedBox(height: 8.0),
                    Row(
                      crossAxisAlignment: CrossAxisAlignment.center,
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Text(
                          'Kota: ${restaurantId.city}',
                          style: const TextStyle(fontSize: 18.0),
                        ),
                        const SizedBox(width: 40.0),
                        Text(
                          'Rating: ${restaurantId.rating.toStringAsFixed(1)}',
                          style: const TextStyle(fontSize: 18.0),
                        ),
                      ],
                    ),

                    const SizedBox(height: 16.0),
                    Text(
                      restaurantId.description,
                      style: const TextStyle(fontSize: 16.0),
                      textAlign: TextAlign.center,
                    ),
                    const SizedBox(height: 25.0),
                    const Text(
                      'Menu :',
                      style: TextStyle(fontSize: 20.0, fontWeight: FontWeight.bold),
                      textAlign: TextAlign.center,
                    ),
                    const SizedBox(height: 18.0),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.center,
                          children: [
                            const Text(
                              'Foods:',
                              style: TextStyle(fontSize: 20.0, fontWeight: FontWeight.bold),
                            ),
                            ...restaurantId.menus.foods.map((food) => Text(food.name)).toList(),
                          ],
                        ),
                        const SizedBox(width: 40.0), // Add some space between columns
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.center,
                          children: [
                            const Text(
                              'Drinks:',
                              style: TextStyle(fontSize: 20.0, fontWeight: FontWeight.bold),
                            ),
                            ...restaurantId.menus.drinks.map((drink) => Text(drink.name)).toList(),
                          ],
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          );
        }
        );
  }
}
