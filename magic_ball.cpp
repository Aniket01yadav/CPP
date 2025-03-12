#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Array of possible answers
    string responses[] = {
        "Yes, definitely! ",
        "Without a doubt! ",
        "Most likely! ",
        "Ask again later... ",
        "Cannot predict now. ",
        "Don't count on it. ",
        "Very doubtful... ",
        "Absolutely! ",
        "Maybe, maybe not.",
        "Better not tell you now. "
    };

    // Ask the user to enter a question
    cout << "Welcome to the Magic 8-Ball!" << endl;
    cout << "Ask a yes/no question: ";
    
    string question;
    getline(cin, question); // Get the full question from the user

    // Generate a random response
    int index = rand() % (sizeof(responses) / sizeof(responses[0]));

    // Display the response
    cout << "Magic 8-Ball says: " << responses[index] << endl;

    return 0;
}
