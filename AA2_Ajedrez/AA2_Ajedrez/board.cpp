#include "board.h"
#include <iostream>
#include <cctype>

using namespace std;

Board::Board() {
    board.resize(8, vector<Piece>(8));
}

void Board::initialize() {
    string initialRows[] = {
        "rnbqkbnr",
        "pppppppp",
        "********",
        "********",
        "********",
        "********",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = Piece(initialRows[i][j], i, j);
        }
    }
}

void Board::print() const {
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j].getSymbol() << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

bool Board::movePiece(const string& from, const string& to, bool isWhiteTurn) {
    int fromRow = 8 - (from[1] - '0');
    int fromCol = from[0] - 'a';
    int toRow = 8 - (to[1] - '0');
    int toCol = to[0] - 'a';

    if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
        toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8) {
        return false;
    }

    Piece& piece = board[fromRow][fromCol];
    if (!piece.isValidMove(toRow, toCol, board, isWhiteTurn)) {
        return false;
    }

    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = Piece('*', fromRow, fromCol);
    board[toRow][toCol].setPosition(toRow, toCol);

    return true;
}

bool Board::isCheckmate(bool isWhiteTurn) const {
    char king = isWhiteTurn ? 'k' : 'K';
    for (const auto& row : board) {
        for (const auto& piece : row) {
            if (piece.getSymbol() == king) {
                return false;
            }
        }
    }
    return true;
}