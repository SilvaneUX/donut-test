import 'package:budget_tracker/screens/home_screen.dart';
import 'package:budget_tracker/screens/login_screens.dart';
import 'package:budget_tracker/screens/transaction_screen.dart';
import 'package:budget_tracker/widgets/navbar.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';

class Dashboard extends StatefulWidget {
  const Dashboard({super.key});

  @override
  State<Dashboard> createState() => _DashboardState();
}

class _DashboardState extends State<Dashboard> {
  var isLogoutLoading = false;
  int currentIndex = 0;
  var PageViewList = [HomeScreen(), TransactionScreen()];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        bottomNavigationBar: NavBar(
          selectedIndex: currentIndex,
          onDestinationSelected: (int value) {
            setState(() {
              currentIndex = value;
            });
          },
        ),
        body: PageViewList[currentIndex]);
  }
}
