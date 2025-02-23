#include <iostream>
#include <iomanip>
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Function to calculate the first day of the month using Zeller's Congruence
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int day = (1 + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
    return (day + 6) % 7; // Adjusting to make Sunday = 0
}

// Function to print the calendar
void printCalendar(int month, int year) {
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int days = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);
    
    cout << "\n  " << months[month - 1] << " " << year << "\n";
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    
    for (int i = 0; i < startDay; i++) {
        cout << "     "; // Print leading spaces
    }
    
    for (int day = 1; day <= days; day++) {
        cout << setw(5) << day;
        if ((startDay + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << "\n";
}

int main() {
    int month, year;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    
    if (month < 1 || month > 12 || year < 1) {
        cout << "Invalid input! Please enter a valid month and year.";
        return 1;
    }
    
    printCalendar(month, year);
    return 0;
}
