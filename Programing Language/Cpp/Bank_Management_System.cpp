#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Class representing a bank account
class BankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;

public:
    // Constructor
    BankAccount(string n, int accNo, string accType, double initialBalance) {
        name = n;
        accountNumber = accNo;
        accountType = accType;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully!\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully!\n";
        }
    }

    // Display account details
    void displayDetails() const {
        cout << "\n----- Account Details -----\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: ₹" << balance << endl;
        cout << "---------------------------\n";
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

// Function prototypes
void createAccount(vector<BankAccount>& accounts);
void depositMoney(vector<BankAccount>& accounts);
void withdrawMoney(vector<BankAccount>& accounts);
void displayAccount(vector<BankAccount>& accounts);
BankAccount* findAccount(vector<BankAccount>& accounts, int accNo);

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle invalid input (non-numeric)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                depositMoney(accounts);
                break;
            case 3:
                withdrawMoney(accounts);
                break;
            case 4:
                displayAccount(accounts);
                break;
            case 5:
                cout << "Exiting... Thank you for using our system!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Create a new account
void createAccount(vector<BankAccount>& accounts) {
    string name, type;
    int accNo;
    double balance;

    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Account Type (Savings/Current): ";
    cin >> type;
    cout << "Enter Initial Deposit: ";
    cin >> balance;

    BankAccount newAcc(name, accNo, type, balance);
    accounts.push_back(newAcc);
    cout << "Account Created Successfully!\n";
}

// Find account by account number
BankAccount* findAccount(vector<BankAccount>& accounts, int accNo) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            return &acc;
        }
    }
    return nullptr;
}

// Deposit money
void depositMoney(vector<BankAccount>& accounts) {
    int accNo;
    double amount;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    BankAccount* acc = findAccount(accounts, accNo);
    if (acc) {
        cout << "Enter amount to deposit: ";
        cin >> amount;
        acc->deposit(amount);
    } else {
        cout << "Account not found!\n";
    }
}

// Withdraw money
void withdrawMoney(vector<BankAccount>& accounts) {
    int accNo;
    double amount;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    BankAccount* acc = findAccount(accounts, accNo);
    if (acc) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        acc->withdraw(amount);
    } else {
        cout << "Account not found!\n";
    }
}

// Display account details
void displayAccount(vector<BankAccount>& accounts) {
    int accNo;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    BankAccount* acc = findAccount(accounts, accNo);
    if (acc) {
        acc->displayDetails();
    } else {
        cout << "Account not found!\n";
    }
}
