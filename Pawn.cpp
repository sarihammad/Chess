#include "Pawn.h"

Pawn::Pawn(Color color) : ChessPiece(color), isEnPassantPiece(false) {
    pieceSprite = loadPiece();
}

Pawn::~Pawn() { }

bool Pawn::isValidMove(Board *board, int new_x, int new_y) {
    int x = getPiecePosition(board).first;
    int y = getPiecePosition(board).second;
    if (pieceColor == board->bottomPlayer) {
        if (x - new_x == 0) {
            if (board->getPieceAt(new_x, new_y) == nullptr && (y - new_y == 1 || (y == 6 && y - new_y == 2 && board->getPieceAt(new_x, 5) == nullptr))) {
                return true;
            } 
        } else if (abs(x - new_x) == 1 && y - new_y == 1) {
            if (board->getColorAt(new_x, new_y) == getOtherColor(pieceColor)) {
                return true;
            } else if (board->getPieceAt(new_x, new_y) == nullptr && board->getTypeAt(new_x, new_y + 1) == "PAWN" && board->getColorAt(new_x, new_y + 1) == getOtherColor(pieceColor)) {
                Pawn *pawn = (Pawn*) board->getPieceAt(new_x, new_y+1);
                return pawn->isEnPassantPiece;
            }
        } 
    } 
    if (pieceColor == board->topPlayer) {
        if (x - new_x == 0) {
            if (board->getPieceAt(new_x, new_y) == nullptr && (new_y - y == 1 || (y == 1 && new_y - y == 2 && board->getPieceAt(new_x, 2) == nullptr))) {
                return true;
            }
        } else if (abs(x - new_x) == 1 && new_y - y == 1) {
            if (board->getColorAt(new_x, new_y) == getOtherColor(pieceColor)) {
                return true;
            } else if (board->getPieceAt(new_x, new_y) == nullptr && board->getTypeAt(new_x, new_y - 1) == "PAWN" && board->getColorAt(new_x, new_y - 1) == getOtherColor(pieceColor)) {
                Pawn *pawn = (Pawn*) board->getPieceAt(new_x, new_y - 1);
                return pawn->isEnPassantPiece;
            }
        }   
    }   
    return false; 
}

std::string Pawn::getPieceType() {
    return "PAWN";
}