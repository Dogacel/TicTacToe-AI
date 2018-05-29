//
// Created by Dogacel on 5/29/2018.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H



enum Player {
    PLAYER_NONE = -1, PLAYER_X = 0, PLAYER_O = 1
};

enum Shape {
    SHAPE_EMPTY = -1, SHAPE_X = 0, SHAPE_O = 1
};

struct Move {
    int x, y;
    Move(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

Player notPlayer(Player player);

class TicTacToe {
public:
    TicTacToe();
    int getScore(Player player);
    Player getTurn();
    Player getWinner();
    Shape getShape(int x, int y);
    bool gameEnded();
    bool makeMove(Move move);
    void printBoard();
    void reset();
    void undoMove(Move move);

private:
    Player turnPlayer;
    Shape board[3][3] = {{SHAPE_EMPTY, SHAPE_EMPTY, SHAPE_EMPTY},
                         {SHAPE_EMPTY, SHAPE_EMPTY, SHAPE_EMPTY},
                         {SHAPE_EMPTY,SHAPE_EMPTY,SHAPE_EMPTY}};
};


#endif //TICTACTOE_H
