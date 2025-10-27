import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

class AppIcons {
  final List<Map<String, dynamic>> homeExpensesCatagories = [
    {
      "name": "Gas Filling",
      "icon": FontAwesomeIcons.gasPump,
    },
    {
      "name": "Grocery",
      "icon": FontAwesomeIcons.shoppingCart,
    },
    {
      "name": "Milk",
      "icon": FontAwesomeIcons.mugHot,
    },
    {
      "name": "Internet",
      "icon": FontAwesomeIcons.wifi,
    },
    {
      "name": "Rent",
      "icon": FontAwesomeIcons.house,
    },
    {
      "name": "Trasportation",
      "icon": FontAwesomeIcons.bus,
    },
    {
      "name": "Electricity",
      "icon": FontAwesomeIcons.boltLightning,
    },
    {
      "name": "Others",
      "icon": FontAwesomeIcons.question,
    }
  ];

  IconData getExpenseCategoryIcons(String categoryName) {
    final category = homeExpensesCatagories.firstWhere(
      (category) => category['name'] == categoryName,
      orElse: () => {
        "name": "Default", // Provide a default name for the default icon
        "icon": FontAwesomeIcons.shoppingCart,
      },
    );
    return category['icon'];
  }
}
