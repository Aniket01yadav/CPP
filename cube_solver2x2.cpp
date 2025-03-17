#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define Cube Movements
vector<string> moves = {"R", "R'", "L", "L'", "U", "U'", "D", "D'", "F", "F'", "B", "B'"};

// A simplified representation of a 2x2 cube state
struct Cube {
    vector<int> state;

    Cube() {
        state = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5};
    }

    void applyMove(string move) {
        if (move == "R") { rotateRight(); }
        else if (move == "R'") { rotateRight(); rotateRight(); rotateRight(); }
        else if (move == "U") { rotateUp(); }
        else if (move == "U'") { rotateUp(); rotateUp(); rotateUp(); }
        else if (move == "F") { rotateFront(); }
        else if (move == "F'") { rotateFront(); rotateFront(); rotateFront(); }
    }

    void rotateRight() {
        swap(state[1], state[5]);
        swap(state[5], state[9]);
        swap(state[9], state[13]);
        swap(state[2], state[6]);
        swap(state[6], state[10]);
        swap(state[10], state[14]);
    }

    void rotateUp() {
        swap(state[0], state[2]);
        swap(state[2], state[3]);
        swap(state[3], state[1]);
        swap(state[8], state[12]);
        swap(state[12], state[16]);
        swap(state[16], state[4]);
    }

    void rotateFront() {
        swap(state[4], state[6]);
        swap(state[6], state[7]);
        swap(state[7], state[5]);
        swap(state[8], state[16]);
        swap(state[16], state[20]);
        swap(state[20], state[12]);
    }

    bool isSolved() {
        for (int i = 0; i < 24; i += 4) {
            if (!(state[i] == state[i + 1] && state[i] == state[i + 2] && state[i] == state[i + 3])) return false;
        }
        return true;
    }

    void scramble() {
        for (int i = 0; i < 10; i++) {
            int randMove = rand() % moves.size();
            applyMove(moves[randMove]);
        }
    }

    void printState() {
        for (int i = 0; i < 24; i++) {
            cout << state[i] << " ";
            if ((i + 1) % 4 == 0) cout << endl;
        }
        cout << endl;
    }
};

void solveCube(Cube &cube) {
    vector<string> solution;
    for (string move : moves) {
        cube.applyMove(move);
        if (cube.isSolved()) {
            solution.push_back(move);
            break;
        }
        cube.applyMove(move + "'");
    cout << "Solution: ";
    for (string m : solution) cout << m << " ";
    cout << endl;
}

int main() {
    Cube cube;
    cout << "Scrambling Cube..." << endl;
    cube.scramble();
    cube.printState();

    cout << "Solving Cube..." << endl;
    solveCube(cube);

    cout << "Final Cube State:" << endl;
    cube.printState();

    return 0;
}
