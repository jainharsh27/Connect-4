#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

char board[ROWS][COLS];

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "-----------------------------\n";
}

// Function to make a move in the game
void makeMove(int column, char player) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][column] == ' ') {
            board[i][column] = player;
            return;
        }
    }
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check horizontal
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // Check vertical
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check diagonal (from top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Check diagonal (from top-right to bottom-left)
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 3; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    initializeBoard();
    displayBoard();

    char currentPlayer = 'X';

    // Game loop
    for (int move = 0; move < ROWS * COLS; ++move) {
        int column;
        cout << "Player " << currentPlayer << ", enter your move (column 1-7): ";
        cin >> column;

        // Adjust column to 0-based index
        column--;

        if (column < 0 || column >= COLS || board[0][column] != ' ') {
            cout << "Invalid move. Try again.\n";
            move--;
            continue;
        }

        makeMove(column, currentPlayer);
        displayBoard();

        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Game over. It's a draw!\n";

    return 0;
}
