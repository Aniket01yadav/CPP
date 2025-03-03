#include <iostream>

using namespace std;

int main() {
    int currentAge, maxAge = 70;
    int remainingYears, remainingMonths, remainingDays;

    // Taking user input
    cout << "Enter your current age: ";
    cin >> currentAge;

    // Calculating remaining time
    remainingYears = maxAge - currentAge;
    remainingMonths = remainingYears * 12;
    remainingDays = remainingYears * 365;

    // Display result
    if (remainingYears > 0) {
        cout << "You have " << remainingYears << " years, ";
        cout << remainingMonths << " months, and ";
        cout << remainingDays << " days remaining to reach 70." << endl;
    } else {
        cout << "You have already lived 70 or more years!" << endl;
    }

    return 0;
}
