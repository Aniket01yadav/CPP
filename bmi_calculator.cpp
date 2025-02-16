#include <iostream>
using namespace std;

int main() {
    
    float weight, height, bmi;

    // Input weight and height from the user
    cout << "Enter your weight in kilograms: ";
    cin >> weight;

    cout << "Enter your height in meters: ";
    cin >> height;

    // Calculate BMI
    bmi = weight / (height * height);

    // Display the BMI value
    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Category: Underweight" << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Category: Normal weight" << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "Category: Overweight" << endl;
    } else {
        cout << "Category: Obese" << endl;
    }

    return 0;
}