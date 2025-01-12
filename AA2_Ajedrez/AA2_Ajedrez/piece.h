#pragma once
#define PIECE_H

#include <vector>
#include <string>

class Piece {
private:
    char symbol;
    int row, col;

public:
    Piece(char symbol = '*', int row = 0, int col = 0);
    char getSymbol() const;
    void setPosition(int newRow, int newCol);
    bool isValidMove(int toRow, int toCol, const std::vector<std::vector<Piece>>& board, bool isWhiteTurn) const;
};

