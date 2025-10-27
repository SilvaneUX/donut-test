class AppValidator {
  String? validateEmail(value) {
    if (value!.isEmpty) {
      return 'Please enter an email';
    }
    RegExp emailRegExp =
        RegExp(r'^[a-zA-Z0-9_.-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$');
    if (!emailRegExp.hasMatch(value)) {
      return 'Please enter a valid email';
    }
    return null;
  }

  String? validatePhoneNumber(value) {
    if (value!.isEmpty) {
      return 'Please enter a phone number';
    }
    if (value.length < 10) {
      return 'Please enter a 12-digit phone number';
    }
    return null;
  }

  String? validateUsername(value) {
    if (value!.isEmpty) {
      return 'Please enter your username';
    }
    return null;
  }

  String? validatePassword(value) {
    if (value!.isEmpty) {
      return 'Please enter your Password';
    }
    return null;
  }

  String? isEmptyCheck(value) {
    if (value!.isEmpty) {
      return 'Please fill details';
    }
    return null;
  }
}
