#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct Transaction {
    string type;
    string description;
    double amount;
};

class FinanceManager {
private:
    vector<Transaction> transactions;
    double balance;

public:
    FinanceManager() : balance(0.0) {}

    // Add transactions
    void addTransaction(const string &type, const string &description, double amount) {
        Transaction t = {type, description, amount};
        transactions.push_back(t);
        balance += (type == "Income") ? amount : -amount;
    }

    // Display all transactions
    void displayTransactions() const {
        cout << "\n--- Transactions ---\n";
        cout << left << setw(12) << "Type" << setw(20) << "Description" << setw(10) << "Amount" << endl;
        cout << "----------------------------------------\n";

        for (const auto &t : transactions) {
            cout << setw(12) << t.type << setw(20) << t.description 
                 << fixed << setprecision(2) << setw(10) << t.amount << endl;
        }

        cout << "\nCurrent Balance: $" << fixed << setprecision(2) << balance << "\n";
    }

    // Save to file 
    void saveToFile(const string &filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << balance << endl;
            for (const auto &t : transactions) {
                outFile << t.type << " " << t.description << " " << t.amount << endl;
            }
            outFile.close();
            cout << "Data saved successfully.\n";
        } else {
            cerr << "Error: Unable to save data.\n";
        }
    }

    // Load from file here
    void loadFromFile(const string &filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            inFile >> balance;
            Transaction t;
            while (inFile >> t.type >> t.description >> t.amount) {
                transactions.push_back(t);
            }
            inFile.close();
            cout << "Data loaded successfully.\n";
        } else {
            cout << "No previous data found. Starting fresh.\n";
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    FinanceManager manager;
    manager.loadFromFile("finances.txt");

    int choice;
    do {
        cout << "\n--- Personal Finance Manager ---\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View Transactions\n";
        cout << "4. Save and Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            string desc;
            double amount;
            cout << "Enter description: ";
            cin >> desc;
            cout << "Enter amount: ";
            cin >> amount;

            if (choice == 1) {
                manager.addTransaction("Income", desc, amount);
            } else {
                manager.addTransaction("Expense", desc, amount);
            }
        } else if (choice == 3) {
            manager.displayTransactions();
        }
    } while (choice != 4);

    manager.saveToFile("finances.txt");

    cout << "Exiting program. Goodbye!\n";
    return 0;
}
