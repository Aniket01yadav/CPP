#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 3;  // Board size
char board[SIZE][SIZE] = {{'1', '2', '3'},
                          {'4', '5', '6'},
                          {'7', '8', '9'}};

// Function to display the board
void displayBoard() {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---+---+---\n";
    }
    cout << endl;
}

// Function to check if the current player has won
bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||   // Row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {   // Column
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Diagonal 1
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  // Diagonal 2
        return true;
    }

    return false;
}

// Function to check if the board is full (draw)
bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // Empty spot found, not a draw
            }
        }
    }
    return true;  // No empty spots, it's a draw
}

// Function to handle the player's move
bool makeMove(char player, int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;

    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again!\n";
        return false;
    }

    board[row][col] = player;
    return true;
}

int main() {
    char currentPlayer = 'X';
    int move;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    
    // Game loop
    while (!gameOver) {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (!makeMove(currentPlayer, move)) {
            continue;  // Invalid move, try again
        }

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            gameOver = true;
        } else if (isDraw()) {
            displayBoard();
            cout << "It's a draw! 🤝\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch player
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
