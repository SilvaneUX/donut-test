import 'dart:isolate';

import 'package:budget_tracker/screens/login_screens.dart';
import 'package:budget_tracker/services/auth_service.dart';
import 'package:budget_tracker/util/appvalidator.dart';
import 'package:flutter/material.dart';

class SignUpView extends StatefulWidget {
  SignUpView({super.key});

  @override
  State<SignUpView> createState() => _SignUpViewState();
}

class _SignUpViewState extends State<SignUpView> {
  final GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  final _userNameController = TextEditingController();

  final _emailController = TextEditingController();

  final _phoneController = TextEditingController();

  final _passwordController = TextEditingController();

  var authService = AuthService();
  var isLoader = false;

  Future<void> _submitform() async {
    if (_formKey.currentState!.validate()) {
      setState(() {
        isLoader = true;
      });

      var data = <String, dynamic>{};
      data['username'] = _userNameController.text;
      data['email'] = _emailController.text;
      data['password'] = _passwordController.text;
      data['phone'] = _phoneController.text;
      data['remainingAmount'] = 0;
      data['totalCredit'] = 0;
      data['totalDebit'] = 0;
      // var data; = {
      //   "username" = _userNameController.text,
      //   "email" = _emailController.text,
      //   "password" = _passwordController.text,
      //   "phone" = _phoneController.text
      // };
      await authService.createUser(data, context);
      setState(() {
        isLoader = false;
      });
      // ScaffoldMessenger.of(_formKey.currentContext!).showSnackBar(
      //     const SnackBar(content: Text('Form submitted successfully')));
    }
  }

  var appValidator = AppValidator();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color(0xff252634),
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Form(
              key: _formKey,
              child: Column(
                children: [
                  SizedBox(
                    height: 80.0,
                  ),
                  SizedBox(
                    width: 250,
                    child: Text(
                      "Create new Account",
                      textAlign: TextAlign.center,
                      style: TextStyle(
                          color: Colors.white,
                          fontSize: 28,
                          fontWeight: FontWeight.bold),
                    ),
                  ),
                  SizedBox(
                    height: 50,
                  ),
                  TextFormField(
                      controller: _userNameController,
                      style: TextStyle(color: Colors.white),
                      autovalidateMode: AutovalidateMode.onUserInteraction,
                      decoration:
                          _buildInputDecoration("Username", Icons.person),
                      validator: appValidator.validateUsername),
                  SizedBox(
                    height: 16.0,
                  ),
                  TextFormField(
                    controller: _emailController,
                    keyboardType: TextInputType.emailAddress,
                    style: TextStyle(color: Colors.white),
                    autovalidateMode: AutovalidateMode.onUserInteraction,
                    decoration: _buildInputDecoration("Email", Icons.email),
                    validator: appValidator.validateEmail,
                  ),
                  SizedBox(
                    height: 16.0,
                  ),
                  TextFormField(
                    controller: _phoneController,
                    keyboardType: TextInputType.phone,
                    style: TextStyle(color: Colors.white),
                    autovalidateMode: AutovalidateMode.onUserInteraction,
                    decoration:
                        _buildInputDecoration("Phone number", Icons.phone),
                    validator: appValidator.validatePhoneNumber,
                  ),
                  SizedBox(
                    height: 16.0,
                  ),
                  TextFormField(
                    controller: _passwordController,
                    style: TextStyle(color: Colors.white),
                    autovalidateMode: AutovalidateMode.onUserInteraction,
                    decoration: _buildInputDecoration("Password", Icons.lock),
                    validator: appValidator.validatePassword,
                    obscureText: true,
                  ),
                  SizedBox(
                    height: 40.0,
                  ),
                  SizedBox(
                      height: 50.0,
                      width: double.infinity,
                      child: ElevatedButton(
                          style: ElevatedButton.styleFrom(
                              backgroundColor: Colors.yellow),
                          onPressed: () {
                            isLoader ? print("Loading") : _submitform();
                          },
                          child: isLoader
                              ? Center(child: CircularProgressIndicator())
                              : Text("Create",
                                  style: TextStyle(fontSize: 20)))),
                  SizedBox(
                    height: 20.0,
                  ),
                  TextButton(
                      onPressed: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(builder: (context) => LoginView()),
                        );
                      },
                      child: Text("Login",
                          style: TextStyle(
                              color: Colors.yellowAccent, fontSize: 20))),
                ],
              )),
        ),
      ),
    );
  }

  InputDecoration _buildInputDecoration(String label, IconData suffixIcon) {
    return InputDecoration(
        fillColor: Color(0xAA494A59),
        enabledBorder: OutlineInputBorder(
            borderSide: BorderSide(color: Color(0x35949494))),
        focusedBorder:
            OutlineInputBorder(borderSide: BorderSide(color: Colors.white)),
        filled: true,
        labelStyle: TextStyle(color: Color(0xff949494)),
        labelText: label,
        suffixIcon: Icon(
          suffixIcon,
          color: Color(0xFF949494),
        ),
        border: OutlineInputBorder(borderRadius: BorderRadius.circular(10.0)));
  }
}
