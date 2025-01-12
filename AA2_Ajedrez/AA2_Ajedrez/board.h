#pragma once
#define BOARD_H

#include <string>
#include <vector>
#include "piece.h"

class Board {
private:
    std::vector<std::vector<Piece>> board;

public:
    Board();
    void initialize();
    void print() const;
    bool movePiece(const std::string& from, const std::string& to, bool isWhiteTurn);
    bool isCheckmate(bool isWhiteTurn) const;
};

