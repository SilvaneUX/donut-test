import 'package:budget_tracker/util/icons_list.dart';
import 'package:budget_tracker/widgets/transaction_cards.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';

class TransactionCards extends StatelessWidget {
  TransactionCards({super.key});

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.all(5),
          child: Column(
            children: [
              Row(
                children: [
                  Text(
                    "Recent Transaction",
                    style: TextStyle(
                      fontSize: 20,
                      fontWeight: FontWeight.w600,
                    ),
                  ),
                ],
              ),
              RecentTransactionsList()
            ],
          ),
        )
      ],
    );
  }
}

class RecentTransactionsList extends StatelessWidget {
  RecentTransactionsList({
    super.key,
  });
  final userId = FirebaseAuth.instance.currentUser!.uid;

  @override
  Widget build(BuildContext context) {
    return StreamBuilder<QuerySnapshot>(
        stream: FirebaseFirestore.instance
            .collection('users')
            .doc(userId)
            .collection("transaction")
            .orderBy('timestamp', descending: true)
            .limit(10)
            .snapshots(),
        builder: (BuildContext context, AsyncSnapshot<QuerySnapshot> snapshot) {
          if (snapshot.hasError) {
            return Text('Something went wrong');
          } else if (snapshot.connectionState == ConnectionState.waiting) {
            return Text("Loading");
          } else if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
            return const Center(child: Text("No transaction found"));
          }
          var data = snapshot.data!.docs;

          return ListView.builder(
              shrinkWrap: true,
              itemCount: data.length,
              physics: NeverScrollableScrollPhysics(),
              itemBuilder: (context, index) {
                var cardData = data[index];
                return TransactionCard(
                  data: cardData,
                );
              });
        });
  }
}
