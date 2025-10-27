import 'package:budget_tracker/util/appvalidator.dart';
import 'package:budget_tracker/widgets/category_dropdown.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:uuid/uuid.dart';
import 'package:intl/intl.dart';

class AddTransactionForm extends StatefulWidget {
  const AddTransactionForm({super.key});

  @override
  State<AddTransactionForm> createState() => _AddTransactionFormState();
}

class _AddTransactionFormState extends State<AddTransactionForm> {
  var type = "credit";
  var category = "Others";

  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();
  var isLoader = false;
  var appValidator = AppValidator();
  var amountEditController = TextEditingController();
  var titleEditController = TextEditingController();
  var uid = Uuid();

  Future<void> _submitform() async {
    if (_formKey.currentState!.validate()) {
      setState(() {
        isLoader = true;
      });
      final user = FirebaseAuth.instance.currentUser;
      int timestamp = DateTime.now().millisecondsSinceEpoch;
      var amount = int.parse(amountEditController.text);
      DateTime date = DateTime.now();

      var id = uid.v4();
      String mm, monthyear = DateFormat('MMM y').format(date);
      final userDoc = await FirebaseFirestore.instance
          .collection('users')
          .doc(user!.uid)
          .get();

      int remainingAmount = userDoc['remainingAmount'];
      int totalCredit = userDoc['totalCredit'];
      int totalDebit = userDoc['totalDebit'];

      if (type == 'credit') {
        remainingAmount += amount;
        totalCredit += amount;
      } else {
        remainingAmount -= amount;
        totalDebit += amount;
      }

      await FirebaseFirestore.instance
          .collection('users')
          .doc(user!.uid)
          .update({
        "remainingAmount": remainingAmount,
        "totalCredit": totalCredit,
        "totalDebit": totalDebit,
        "UpdateAt": timestamp,
      });
      var data = <String, dynamic>{};
      data['id'] = id;
      data['title'] = titleEditController.text;
      data['amount'] = amount;
      data['type'] = type;
      data['timestamp'] = timestamp;
      data['totalCredit'] = totalCredit;
      data['totalDebit'] = totalDebit;
      data['remainingAmount'] = remainingAmount;
      data['monthyear'] = monthyear;
      data['category'] = category;

      await FirebaseFirestore.instance
          .collection('users')
          .doc(user!.uid)
          .collection("transaction")
          .doc(id)
          .set(data);
      //await authService.login(data, context);

      Navigator.pop(context);

      setState(() {
        isLoader = false;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Form(
        key: _formKey,
        child: Column(
          children: [
            TextFormField(
              controller: titleEditController,
              validator: appValidator.isEmptyCheck,
              autovalidateMode: AutovalidateMode.onUserInteraction,
              decoration: InputDecoration(
                labelText: 'title',
              ),
            ),
            TextFormField(
              controller: amountEditController,
              validator: appValidator.isEmptyCheck,
              autovalidateMode: AutovalidateMode.onUserInteraction,
              keyboardType: TextInputType.number,
              decoration: InputDecoration(
                labelText: 'amount',
              ),
            ),
            CategoryDropdown(
              cattype: category,
              onChanged: (String? value) {
                if (value != null) {
                  setState(() {
                    category = value;
                  });
                }
              },
            ),
            DropdownButtonFormField(
                value: 'credit',
                items: [
                  DropdownMenuItem(
                    child: Text('Credit'),
                    value: 'credit',
                  ),
                  DropdownMenuItem(
                    child: Text('Debit'),
                    value: 'Debit',
                  ),
                ],
                onChanged: (value) {
                  if (value != null) {
                    setState(() {
                      type = value;
                    });
                  }
                }),
            SizedBox(
              height: 16,
            ),
            ElevatedButton(
                onPressed: () {
                  if (isLoader == false) {
                    _submitform();
                  }
                },
                child: isLoader
                    ? Center(child: CircularProgressIndicator())
                    : Text("Add Transaction"))
          ],
        ),
      ),
    );
  }
}
