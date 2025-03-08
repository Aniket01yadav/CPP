#include <iostream>
#include <vector>
using namespace std;


class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(int accNum, string holder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    void displayBalance() {
        cout << "Account Number: " << accountNumber << " | Holder: " << accountHolder << " | Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice, accNum;
    string name;
    double amount;

    while (true) {
        cout << "\nBanking System Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            accounts.push_back(BankAccount(accNum, name, 0.0));
            cout << "Account created successfully!" << endl;
            break;

        case 2:

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.deposit(amount);
                    break;
                }
            }
            break;

        case 3:

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.withdraw(amount);
                    break;
                }
            }
            break;

        case 4:

            cout << "Enter Account Number: ";
            cin >> accNum;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    acc.displayBalance();
                    break;
                }
            }
            break;

        case 5:
        
            cout << "Exiting program. Thank you!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}