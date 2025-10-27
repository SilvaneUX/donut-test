import 'package:flutter/material.dart';
import 'package:intl/intl.dart';

class TimeLineMonth extends StatefulWidget {
  const TimeLineMonth({super.key, required this.onChanged});
  final ValueChanged<String?> onChanged;

  @override
  State<TimeLineMonth> createState() => _TimeLineMonthState();
}

class _TimeLineMonthState extends State<TimeLineMonth> {
  String currenMonth = "";
  List<String> months = [];
  final scrollController = ScrollController();
  @override
  void initState() {
    super.initState();
    DateTime now = DateTime.now();
    for (int i = -18; i < 1; i++) {
      months.add(
          DateFormat('MMM y').format(DateTime(now.year, now.month + i, 1)));
    }
    currenMonth = DateFormat('MMM y').format(now);

    Future.delayed(Duration(seconds: 1), () {
      scrollToSelectedMonth();
    });
  }

  scrollToSelectedMonth() {
    final SelectedMonthIndex = months.indexOf(currenMonth);
    if (SelectedMonthIndex != -1) {
      final scrollOffset = (SelectedMonthIndex * 100.0) - 170;
      scrollController.animateTo(scrollOffset,
          duration: Duration(milliseconds: 500), curve: Curves.ease);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 40,
      child: ListView.builder(
          controller: scrollController,
          itemCount: months.length,
          scrollDirection: Axis.horizontal,
          itemBuilder: (context, index) {
            return GestureDetector(
              onTap: () {
                setState(() {
                  currenMonth = months[index];
                  widget.onChanged(months[index]);
                });
                scrollToSelectedMonth();
              },
              child: Container(
                width: 80,
                margin: EdgeInsets.all(8),
                decoration: BoxDecoration(
                    color: currenMonth == months[index]
                        ? Colors.blue.shade900.withOpacity(0.5)
                        : Colors.red.withOpacity(0.1),
                    borderRadius: BorderRadius.circular(20)),
                child: Center(child: Text(months[index])),
              ),
            );
          }),
    );
  }
}
