#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char> >& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    for (size_t i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false; // No win
}

bool checkDraw(const std::vector<std::vector<char> >& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false; // Empty cell found, game not a draw
            }
        }
    }
    return true; // All cells filled, game is a draw
}

int main() {
    std::vector<std::vector<char> > board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
        std::cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

