#include <iostream>
#include "board.h"
#include "piece.h"

using namespace std;

int main() {
    Board chessBoard;
    chessBoard.initialize();

    bool isWhiteTurn = true;
    string from, to;

    while (true) {
        chessBoard.print();

        if (chessBoard.isCheckmate(isWhiteTurn)) {
            cout << (isWhiteTurn ? "Negras" : "Blancas") << " ganan por jaque mate." << endl;
            break;
        }

        cout << (isWhiteTurn ? "Blancas" : "Negras") << " mueven. Ingresa movimiento (e.g., e2 e4): ";
        cin >> from >> to;

        if (!chessBoard.movePiece(from, to, isWhiteTurn)) {
            cout << "Movimiento inválido." << endl;
            continue;
        }

        isWhiteTurn = !isWhiteTurn;
    }

    return 0;
}

