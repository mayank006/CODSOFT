#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<char> board(9, ' ');

void displayBoard() {
    cout << "\n";
    cout << "  Positions       Current Board\n";
    cout << "  1 | 2 | 3       " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "  ---------       -----------\n";
    cout << "  4 | 5 | 6       " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "  ---------       -----------\n";
    cout << "  7 | 8 | 9       " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

void resetBoard() {
    fill(board.begin(), board.end(), ' ');
}

const int WIN_LINES[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8},
    {0,3,6}, {1,4,7}, {2,5,8},
    {0,4,8}, {2,4,6}
};

bool checkWin(char sym) {
    for (auto& line : WIN_LINES)
        if (board[line[0]] == sym && board[line[1]] == sym && board[line[2]] == sym)
            return true;
    return false;
}

bool checkDraw() {
    for (char c : board)
        if (c == ' ') return false;
    return true;
}

int getMove(char sym) {
    int pos;
    while (true) {
        cout << "  Player " << sym << ", enter position (1-9): ";
        if (!(cin >> pos)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a number.\n";
            continue;
        }
        if (pos < 1 || pos > 9) {
            cout << "  Out of range. Choose between 1 and 9.\n";
            continue;
        }
        if (board[pos - 1] != ' ') {
            cout << "  That cell is already taken. Try another.\n";
            continue;
        }
        return pos - 1;
    }
}

int main() {
    int winsX = 0, winsO = 0, draws = 0;
    char players[2] = {'X', 'O'};
    char playAgain;

    cout << "================================\n";
    cout << "       TIC-TAC-TOE GAME\n";
    cout << "================================\n";
    cout << "  Player 1 = X    Player 2 = O\n";

    do {
        resetBoard();
        int turn = 0;
        bool gameOver = false;

        cout << "\n--- New Game ---\n";
        cout << "Scores  X: " << winsX << "  O: " << winsO << "  Draws: " << draws << "\n";

        while (!gameOver) {
            char current = players[turn % 2];
            displayBoard();

            int idx = getMove(current);
            board[idx] = current;

            if (checkWin(current)) {
                displayBoard();
                cout << "  *** Player " << current << " wins! ***\n";
                (current == 'X') ? winsX++ : winsO++;
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "  *** It's a draw! ***\n";
                draws++;
                gameOver = true;
            }
            turn++;
        }

        cout << "\nUpdated Scores  X: " << winsX << "  O: " << winsO << "  Draws: " << draws << "\n";
        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n=== Final Scores ===\n";
    cout << "  X: " << winsX << " wins\n";
    cout << "  O: " << winsO << " wins\n";
    cout << "  Draws: " << draws << "\n";
    cout << "Thanks for playing!\n";

    return 0;
}