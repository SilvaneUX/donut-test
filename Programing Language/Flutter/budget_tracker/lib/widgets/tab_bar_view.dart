import 'package:budget_tracker/widgets/transaction_list.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';

class TypeTabBar extends StatelessWidget {
  const TypeTabBar(
      {super.key, required this.category, required this.monthYear});
  final String category;
  final String monthYear;

  @override
  Widget build(BuildContext context) {
    return Expanded(
        child: DefaultTabController(
      length: 2,
      child: Column(children: [
        TabBar(tabs: [
          Tab(
            text: "Credit",
          ),
          Tab(
            text: "Debit",
          ),
        ]),
        Expanded(
            child: TabBarView(
          children: [
            TransectionList(
              category: category,
              type: 'credit',
              monthYear: monthYear,
            ),
            TransectionList(
              category: category,
              type: 'Debit',
              monthYear: monthYear,
            ),
          ],
        ))
      ]),
    ));
  }
}
