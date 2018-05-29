//
// Created by Dogacel on 5/29/2018.
//
#include <iostream>
#include "TicTacToe.h"

using namespace std;

char shapeToChar(Shape s) {
    if (s == SHAPE_X)
        return 'X';
    if (s == SHAPE_O)
        return 'O';
    return ' ';
}

TicTacToe::TicTacToe() {
    turnPlayer = PLAYER_X;
}

void TicTacToe::printBoard() {
    cout << "-------" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "|" << shapeToChar(board[row][col]);
        }
        cout << "|" << endl;
        cout << "-------" << endl;
    }
}


bool TicTacToe::gameEnded() {
    if (getWinner() == PLAYER_NONE) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == SHAPE_EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    return true;
}

vector<Move> TicTacToe::generateMoves() {
    vector<Move> returnVector = vector<Move>();
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == SHAPE_EMPTY) {
                returnVector.push_back(Move(row, col));
            }
        }
    }

    return returnVector;
}

Player TicTacToe::getWinner() {
    if (board[0][0] == board[1][1]
        && board[1][1] == board[2][2]) {
        return (Player) board[0][0];
    }

    if (board[2][0] == board[1][1]
        && board[1][1] == board[0][2]) {
        return (Player) board[2][0];
    }

    for (int i = 0 ; i < 3 ; i++) {
        if (board[i][0] == board[i][1]
            && board[i][1] == board[i][2]) {
            return (Player) board[i][0];
        }

        if (board[0][i] == board[1][i]
            && board[1][i] == board[2][i]) {
            return (Player) board[0][i];
        }
    }

    return PLAYER_NONE;
}

int TicTacToe::getScore(Player player) {
    if (getWinner() == PLAYER_NONE)
        return 0; //Draw
    if (getWinner() == player)
        return 1; //Win
    return -1; //Lose
}

Player TicTacToe::getTurn() {
    return turnPlayer;
}

Player notPlayer(Player p) {
    if (p == PLAYER_NONE)
        return p;
    if (p == PLAYER_X)
        return PLAYER_O;
    return PLAYER_X;
}

void TicTacToe::reset() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = SHAPE_EMPTY;
            turnPlayer = PLAYER_X;
        }
    }
}

void TicTacToe::undoMove(Move move) {
    turnPlayer = notPlayer(turnPlayer);
    if (move.x >= 0 && move.x <= 3 && move.y >= 0 && move.x <= 3) {
        board[move.x][move.y] = SHAPE_EMPTY;
    }
}

bool TicTacToe::makeMove(Move move) {
    if (move.x >= 0 && move.x <= 3 && move.y >= 0 && move.x <= 3) {
        if (board[move.x][move.y] == SHAPE_EMPTY) {
            board[move.x][move.y] = (Shape) turnPlayer;
            turnPlayer = notPlayer(turnPlayer);
            return true;
        }
    }

    return false;
}