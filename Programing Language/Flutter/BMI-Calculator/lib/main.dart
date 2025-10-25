import 'package:flutter/material.dart';
import 'dart:math';

void main() {
  runApp(const BMICalculatorApp());
}

class BMICalculatorApp extends StatelessWidget {
  const BMICalculatorApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'BMI Calculator',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const BMIScreen(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class BMIScreen extends StatefulWidget {
  const BMIScreen({super.key});

  @override
  State<BMIScreen> createState() => _BMIScreenState();
}

class _BMIScreenState extends State<BMIScreen> {
  final TextEditingController _heightController = TextEditingController();
  final TextEditingController _weightController = TextEditingController();
  double? _bmi;
  String _category = "";

  void _calculateBMI() {
    final double? height = double.tryParse(_heightController.text);
    final double? weight = double.tryParse(_weightController.text);

    if (height == null || weight == null || height <= 0 || weight <= 0) {
      setState(() {
        _bmi = null;
        _category = "Please enter valid numbers!";
      });
      return;
    }

    final double bmi = weight / pow(height / 100, 2);

    String category;
    if (bmi < 18.5) {
      category = "Underweight";
    } else if (bmi < 24.9) {
      category = "Normal";
    } else if (bmi < 29.9) {
      category = "Overweight";
    } else {
      category = "Obese";
    }

    setState(() {
      _bmi = bmi;
      _category = category;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('BMI Calculator'),
        centerTitle: true,
      ),
      body: Padding(
        padding: const EdgeInsets.all(20.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            TextField(
              controller: _heightController,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                labelText: "Height (cm)",
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 15),
            TextField(
              controller: _weightController,
              keyboardType: TextInputType.number,
              decoration: const InputDecoration(
                labelText: "Weight (kg)",
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 25),
            ElevatedButton(
              onPressed: _calculateBMI,
              child: const Text("Calculate BMI"),
            ),
            const SizedBox(height: 25),
            if (_bmi != null)
              Column(
                children: [
                  Text(
                    "Your BMI is ${_bmi!.toStringAsFixed(2)}",
                    style: const TextStyle(
                      fontSize: 22,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  const SizedBox(height: 8),
                  Text(
                    "Category: $_category",
                    style: const TextStyle(fontSize: 18),
                  ),
                ],
              ),
            if (_bmi == null && _category.isNotEmpty)
              Text(
                _category,
                style: const TextStyle(color: Colors.red, fontSize: 18),
              ),
          ],
        ),
      ),
    );
  }
}
