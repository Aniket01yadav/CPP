#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Array of fortunes
    string fortunes[] = {
        "You will have a great day! 😊",
        "An exciting opportunity is coming your way! 🚀",
        "Hard work will soon pay off. 💪",
        "A pleasant surprise is waiting for you! 🎁",
        "Be patient; good things take time. ⏳",
        "Success is on the horizon! 🌟",
        "Happiness is closer than you think. ❤️",
        "Your kindness will be rewarded. 🌼",
        "A new adventure is around the corner! 🏞️",
        "Trust yourself—you are capable of great things! 💡"
    };

    // Get the total number of fortunes dynamically
    int arraySize = sizeof(fortunes) / sizeof(fortunes[0]);

    // Generate a random index
    int index = rand() % arraySize;

    // Display the fortune
    cout << "🔮 Your Fortune: " << fortunes[index] << endl;

    return 0;
}
