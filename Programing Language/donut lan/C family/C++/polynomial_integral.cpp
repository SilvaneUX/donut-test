#include <iostream>
#include <vector>

using namespace std;

void display(int highestGrade, vector<double> constList, const char* displayString, char const_variable) {
    // Display
    cout << displayString << " : ";
    int temp_grade = highestGrade;

    for(int i = 0; i < constList.size(); i++) {

        cout << constList[i];

        if(temp_grade != 0) {
            cout << const_variable;
            if(temp_grade > 1) {
                cout << "^" << temp_grade;
            }
            if(i != constList.size() - 1)
                cout << " + ";
        }
        temp_grade--;
    }
    cout << endl;
}

int main() {
    system("CLS");
    // Get highest grade of polynom
    int grade;

    cout << "Input highes grade for x :" << endl;
    cin >> grade;

    // Input constant
    grade++; // add last const
    vector<double> const_number(grade);
    for(int i = grade;i > 0;i--) {
        cout << "Input const number " << (grade - i) + 1 << " :" << endl;
        cin >> const_number[grade - i];
    }

    // Input Limit
    vector<int> limit(2);
    for(int i = 0; i < limit.size(); i++) {
        cout << "Input limit or range " << ((i == 0) ? "up" : "down") << " :" << endl;
        cin >> limit[i];
    }

    display(grade - 1, const_number, "Polynom   ", 'x');

    // Integral
    double temp_grade = grade;
    for(int i = 0; i < const_number.size(); i++) {
        const_number[i] = static_cast<double>(const_number[i] / temp_grade);
        temp_grade--;
    }

    display(grade, const_number, "Integraled", 'x');

    // Calculate with limit
    int index_limit = 0;
    double result[2] = {
        0, 0
    };
    while(index_limit < limit.size()) {

        for(int i = grade; i > 0; i--) {

            double temp_result = limit[index_limit];
            double variable = limit[index_limit];
            temp_grade = i;
            for(int j = 2; j <= temp_grade; j++) {
                temp_result *= variable;
                // cout << "LOG : " << temp_result << endl;
            }

            // cout << "Temp Result : " << const_number[grade - i] * temp_result << endl;
            result[index_limit] += const_number[grade - i] * temp_result;
            // cout << "Result : " <<  result[index_limit] << endl;
        }

        // cout << "Swith Limit" << endl;
        index_limit++;
    }

    cout << "Result     : " << result[0] - result[1] << endl;

    cin.get();
    cout << "Press any key...";
    cin.get();
}
