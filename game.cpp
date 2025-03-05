#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ATTEMPTS = 7;

void playGame() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;
    
    cout << "\nWelcome to the Number Guessing Game!" << endl;
    cout << "Guess a number between 1 and 100. You have " << MAX_ATTEMPTS << " attempts." << endl;
    
    while (attempts < MAX_ATTEMPTS) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber)
            cout << "Too high! Try again." << endl;
        else if (guess < secretNumber)
            cout << "Too low! Try again." << endl;
        else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts!" << endl;
            return;
        }
    
        if (attempts == MAX_ATTEMPTS) {
            cout << "\nSorry, you've used all " << MAX_ATTEMPTS << " attempts. The number was " << secretNumber << "." << endl;
        }
    }
}

int main() {
    char choice;
    
    do {
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    cout << "\nThanks for playing! Goodbye!" << endl;
    return 0;
}
