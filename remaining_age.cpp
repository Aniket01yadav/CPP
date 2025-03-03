#include <iostream>

using namespace std;

// Function to check leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to calculate remaining age
void calculateRemainingAge(int birthDay, int birthMonth, int birthYear) {
    
    int maxAge = 70;
    int currentDay, currentMonth, currentYear;

    // Get current date from user
    cout << "Enter today's date (DD MM YYYY): ";
    cin >> currentDay >> currentMonth >> currentYear;

    // Calculate the target date (70 years from birth)
    int targetYear = birthYear + maxAge;
    int targetMonth = birthMonth;
    int targetDay = birthDay;

    // Adjust for month and day differences
    int remainingYears = targetYear - currentYear;
    int remainingMonths = targetMonth - currentMonth;
    int remainingDays = targetDay - currentDay;

    // Handle negative months
    if (remainingMonths < 0) {
        remainingYears--;
        remainingMonths += 12;
    }

    // Handle negative days
    if (remainingDays < 0) {
        remainingMonths--;
        int daysInPrevMonth;

        // Determine days in previous month
        if (currentMonth == 1) {
            daysInPrevMonth = 31;
        } else if (currentMonth == 3) {
            daysInPrevMonth = isLeapYear(currentYear) ? 29 : 28;
        } else if (currentMonth == 5 || currentMonth == 7 || currentMonth == 10 || currentMonth == 12) {
            daysInPrevMonth = 30;
        } else {
            daysInPrevMonth = 31;
        }

        remainingDays += daysInPrevMonth;
    }

    
    if (remainingYears >= 0) {
        cout << "You have " << remainingYears << " years, " 
             << remainingMonths << " months, and " 
             << remainingDays << " days remaining to reach 70." << endl;
    } else {
        cout << "You have already lived 70 or more years!" << endl;
    }
}

int main() {
    int birthDay, birthMonth, birthYear;

    // Taking user input for birth date
    cout << "Enter your birth date (DD MM YYYY): ";
    cin >> birthDay >> birthMonth >> birthYear;

    calculateRemainingAge(birthDay, birthMonth, birthYear);

    return 0;
}
