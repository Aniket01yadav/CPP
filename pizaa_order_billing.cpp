#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to store pizza details
struct Pizza {
    string name;
    double price;
};

// Function to display menu
void displayMenu(const vector<Pizza> &menu) {
    cout << "\nPizza Menu:" << endl;
    for (size_t i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price << endl;
    }
}

int main() {
    vector<Pizza> menu = {
        {"Margherita", 8.99},
        {"Pepperoni", 10.99},
        {"BBQ Chicken", 12.49},
        {"Veggie", 9.99},
        {"Hawaiian", 11.49}
    };
    
    vector<int> quantities(menu.size(), 0);
    char choice;
    int pizzaNumber, quantity;
    double total = 0.0;
    const double TAX_RATE = 0.08; // 8% tax
    
    do {
        displayMenu(menu);
        cout << "\nEnter the number of the pizza you want to order: ";
        cin >> pizzaNumber;
        
        if (pizzaNumber < 1 || pizzaNumber > menu.size()) {
            cout << "Invalid choice. Try again." << endl;
            continue;
        }
        
        cout << "Enter quantity: ";
        cin >> quantity;
        
        if (quantity < 1) {
            cout << "Invalid quantity. Try again." << endl;
            continue;
        }
        
        quantities[pizzaNumber - 1] += quantity;
        
        cout << "Do you want to order another pizza? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    cout << "\nFinal Bill:" << endl;
    cout << "_________________________________" << endl;
    cout << left << setw(15) << "Pizza" << setw(10) << "Quantity" << setw(10) << "Total" << endl;
    cout << "_________________________________" << endl;
    
    for (size_t i = 0; i < menu.size(); i++) {
        if (quantities[i] > 0) {
            double itemTotal = menu[i].price * quantities[i];
            total += itemTotal;
            cout << left << setw(15) << menu[i].name << setw(10) << quantities[i] << "$" << fixed << setprecision(2) << itemTotal << endl;
        }
    }
    
    double tax = total * TAX_RATE;
    double grandTotal = total + tax;
    
    cout << "_________________________________" << endl;
    cout << "Subtotal: $" << fixed << setprecision(2) << total << endl;
    cout << "Tax (8%): $" << fixed << setprecision(2) << tax << endl;
    cout << "Grand Total: $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "_________________________________" << endl;
    
    cout << "Thank you for your order! Enjoy your pizza!" << endl;
    
    return 0;
}