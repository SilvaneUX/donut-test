import 'package:budget_tracker/screens/login_screens.dart';
import 'package:budget_tracker/widgets/add_transaction.dart';
import 'package:budget_tracker/widgets/hero_card.dart';
import 'package:budget_tracker/widgets/transactions_cards.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  var isLogoutLoading = false;

  logOut() async {
    setState(() {
      isLogoutLoading = true;
    });
    await FirebaseAuth.instance.signOut();

    Navigator.of(context).pushReplacement(
      MaterialPageRoute(builder: ((context) => LoginView())),
    );

    setState(() {
      isLogoutLoading = false;
    });
  }

  final userId = FirebaseAuth.instance.currentUser!.uid;

  _dialoBuilder(BuildContext context) {
    return showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          content: AddTransactionForm(),
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      floatingActionButton: FloatingActionButton(
        backgroundColor: Colors.blue.shade900,
        onPressed: (() {
          _dialoBuilder(context);
        }),
        child: Icon(
          Icons.add,
          color: Colors.white,
        ),
      ),
      appBar: AppBar(
        backgroundColor: Colors.blue.shade900,
        title: Text(
          "Budget Tracker",
          style: TextStyle(color: Colors.white),
        ),
        actions: [
          IconButton(
              onPressed: () {
                logOut();
              },
              icon: isLogoutLoading
                  ? CircularProgressIndicator()
                  : Icon(
                      Icons.exit_to_app,
                      color: Colors.white,
                    ))
        ],
      ),
      body: SingleChildScrollView(
        child: Column(
          children: [
            HeroCard(
              userId: userId,
            ),
            TransactionCards(),
          ],
        ),
      ),
    );
  }
}
