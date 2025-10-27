import 'package:flutter/material.dart';

class NavBar extends StatelessWidget {
  const NavBar(
      {super.key,
      required this.selectedIndex,
      required this.onDestinationSelected});
  final int selectedIndex;
  final ValueChanged<int> onDestinationSelected;

  @override
  Widget build(BuildContext context) {
    return NavigationBar(
      selectedIndex: selectedIndex,
      onDestinationSelected: onDestinationSelected,
      indicatorColor: Colors.blue.shade900,
      labelBehavior: NavigationDestinationLabelBehavior.alwaysHide,
      height: 50,
      destinations: const <Widget>[
        NavigationDestination(
          icon: Icon(Icons.home),
          selectedIcon: Icon(
            Icons.home,
            color: Colors.white,
          ),
          label: 'Home',
        ),
        NavigationDestination(
          icon: Icon(Icons.explore),
          selectedIcon: Icon(
            Icons.explore,
            color: Colors.white,
          ),
          label: 'Transaction',
        ),
      ],
    );
  }
}
