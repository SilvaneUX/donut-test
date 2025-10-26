#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    string choices[3] = {"rock", "paper", "scissors"};
    string user;
    int comp = rand() % 3;

    cout << "Enter rock, paper, or scissors: ";
    cin >> user;

    cout << "Computer chose: " << choices[comp] << endl;

    if (user == choices[comp]) {
        cout << "It's a tie!\n";
    }
    else if ((user == "rock" && choices[comp] == "scissors") ||
             (user == "paper" && choices[comp] == "rock") ||
             (user == "scissors" && choices[comp] == "paper")) {
        cout << "You win!\n";
    }
    else {
        cout << "You lose!\n";
    }

    return 0;
}
