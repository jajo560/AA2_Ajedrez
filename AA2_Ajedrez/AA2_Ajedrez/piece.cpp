#include "piece.h"

Piece::Piece(char symbol, int row, int col) : symbol(symbol), row(row), col(col) {}

char Piece::getSymbol() const {
    return symbol;
}

void Piece::setPosition(int newRow, int newCol) {
    row = newRow;
    col = newCol;
}

bool Piece::isValidMove(int toRow, int toCol, const std::vector<std::vector<Piece>>& board, bool isWhiteTurn) const {
    if ((isWhiteTurn && islower(symbol)) || (!isWhiteTurn && isupper(symbol))) {
        return false;
    }

    if ((isWhiteTurn && isupper(board[toRow][toCol].getSymbol())) ||
        (!isWhiteTurn && islower(board[toRow][toCol].getSymbol()))) {
        return false;
    }


    return true;
}