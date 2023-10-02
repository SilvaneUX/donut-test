import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:dcd_newsapp_fundamental/restaurant_details.dart';
import 'package:flutter/material.dart';
import 'package:connectivity_plus/connectivity_plus.dart';
import 'models/restaurant.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Restaurant',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.orangeAccent),
        useMaterial3: true,
      ),
      home: RestaurantListScreen(),
    );
  }
}

class RestaurantListScreen extends StatefulWidget {
  @override
  _RestaurantListScreenState createState() => _RestaurantListScreenState();
}

class _RestaurantListScreenState extends State<RestaurantListScreen> {
  late Future<List<Restaurant>> _restaurantsFuture;
  final TextEditingController _searchController = TextEditingController();
  bool _isLoading = false;
  bool _isConnected = true;

  Future<void> _checkConnectivity() async {
    final connectivityResult = await Connectivity().checkConnectivity();
    setState(() {
      _isConnected = connectivityResult != ConnectivityResult.none;
    });
  }

  Future<void> _searchRestaurants(String keyword) async {
    setState(() {
      _isLoading = true;
    });

    final response = await http.get(Uri.parse('https://restaurant-api.dicoding.dev/search?q=$keyword'));
    if (response.statusCode == 200) {
      final jsonData = json.decode(response.body);
      final restaurantList = jsonData['restaurants'] as List;
      final filteredRestaurants = restaurantList.map((json) => Restaurant.fromJson(json)).toList();

      setState(() {
        _isLoading = false;
        _restaurantsFuture = Future.value(filteredRestaurants);
      });
    } else {
      // Handle error case
      setState(() {
        _isLoading = false;
        _restaurantsFuture = Future.value([]);
      });
    }
  }

  Future<List<Restaurant>> fetchRestaurants() async {
    final response = await http.get(Uri.parse('https://restaurant-api.dicoding.dev/list'));

    if (response.statusCode == 200) {
      final jsonData = json.decode(response.body);
      final restaurantList = jsonData['restaurants'] as List;
      return restaurantList.map((json) => Restaurant.fromJson(json)).toList();
    } else {
      throw Exception('Failed to load restaurants');
    }
  }


  Future<List<Restaurant>> _loadRestaurants() async {
    try {
      final response = await http.get(Uri.parse('${Restaurant.baseUrl}/${Restaurant.listEndpoint}'));
      if (response.statusCode == 200) {
        final jsonData = json.decode(response.body);
        final restaurantList = jsonData['restaurants'] as List;
        final restaurants = restaurantList.map((json) => Restaurant.fromJson(json)).toList();
        return restaurants;
      } else {
        return []; // Return an empty list in case of an error
      }
    } catch (e) {
      print("Error loading data: daftar rsto $e");
      return []; // Return an empty list in case of an error
    }
  }


  @override
  void initState() {
    super.initState();
    _checkConnectivity();
    _restaurantsFuture = _loadRestaurants();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Center(
          child: Text('Restaurant List'),
        ),
      ),
      body: Column(
        children: [
          if (!_isConnected)
            Container(
              color: Colors.red,
              padding: const EdgeInsets.all(8.0),
              child: Row(
                children: [
                  Icon(Icons.error_outline, color: Colors.white),
                  const SizedBox(width: 8.0),
                  Text(
                    'No internet connection. Please check your network settings.',
                    style: TextStyle(color: Colors.white),
                  ),
                ],
              ),
            ),
          Padding(
            padding: const EdgeInsets.all(16.0),
            child: Row(
              children: [
                Expanded(
                  child: TextField(
                    controller: _searchController,
                    decoration: InputDecoration(
                      hintText: 'Cari Resto ...',
                    ),
                  ),
                ),
                const SizedBox(width: 16.0),
                ElevatedButton(
                  onPressed: () {
                    _searchRestaurants(_searchController.text);
                  },
                  child: Text('Cari'),
                ),
              ],
            ),
          ),
          _isLoading
              ? const CircularProgressIndicator()
              : Expanded(
            child: FutureBuilder<List<Restaurant>>(
              future: _restaurantsFuture,
              builder: (BuildContext context, AsyncSnapshot<List<Restaurant>> snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return const Center(
                    child: CircularProgressIndicator(),
                  );
                } else if (snapshot.hasError) {
                  return const Center(
                    child: Text('Error loading data.'),
                  );
                } else if (!snapshot.hasData || snapshot.data!.isEmpty) {
                  return const Center(
                    child: Text('Data tidak ditemukan.'),
                  );
                } else {
                  final restaurants = snapshot.data!;
                  return GridView.builder(
                    gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
                      crossAxisCount: 2,
                      crossAxisSpacing: 16.0,
                      mainAxisSpacing: 16.0,
                    ),
                    itemCount: restaurants.length,
                    itemBuilder: (context, index) {
                      final restaurant = restaurants[index];
                      return Card(
                        child: InkWell(
                          onTap: () {
                            Navigator.push(
                              context,
                              MaterialPageRoute(
                                builder: (context) => RestaurantDetailsPage(restaurantId: restaurant),
                              ),
                            );
                          },
                          child: Column(
                            children: [
                              Image.network(
                                restaurant.pictureId,
                                width: double.infinity,
                                height: 120.0,
                                fit: BoxFit.cover,
                              ),
                              Padding(
                                padding: const EdgeInsets.all(8.0),
                                child: Column(
                                  crossAxisAlignment: CrossAxisAlignment.start,
                                  children: [
                                    Text(restaurant.name, style: TextStyle(fontSize: 16.0)),
                                    Text(restaurant.city),
                                  ],
                                ),
                              ),
                            ],
                          ),
                        ),
                      );
                    },
                  );
                }
              },
            ),
          ),
        ],
      ),
    );
  }
}
