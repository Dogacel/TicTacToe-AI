#include <iostream>
#include <vector>
#include "TicTacToe.h"

using namespace std;


Move bestMove(0,0);
int searchDepth;

int alphaBeta(TicTacToe& game, int alpha, int beta, int depth, Player player) {
    if (depth == 0 || game.gameEnded()) {
        return game.getScore(player);
    }

    for (Move move : game.generateMoves()) {
        game.makeMove(move);
        int score = -alphaBeta(game, -beta, -alpha, depth - 1, notPlayer(player));
        game.undoMove(move);
        if(score >= beta)
            return beta;
        else if(score > alpha) {
            alpha = score;
            if (depth == searchDepth)
                bestMove = move;
        }
    }
    return alpha;
}

int startAlphaBeta(TicTacToe& game, int depth) {
    if (!game.generateMoves().empty())
        bestMove = game.generateMoves()[0];
    searchDepth = depth;
    return alphaBeta(game, -999, 999, depth, game.getTurn());
}

int main(int argc, char const *argv[])
{
    cout << "Started !" << endl;
    cout << "Controls: " << endl;
    cout << "Please enter 2 integers seperated by a space," << endl;
    cout << "Otherwise game may exit or crash." << endl;
    cout << "Enter -1 x to search depth x with alpha-beta pruning algorithm." << endl;
    cout << "Enter -2 0 to reset game" << endl;
    cout << "Enter any two integers x y (-1 < x < 4 && -1 < y < 4) to make a move." << endl;
    cout << "Input: ";

    TicTacToe game = TicTacToe();

    for (int inputx, inputy; cin >> inputx >> inputy; cout << "Input: ") {
        if (inputx == -2) {
            game.reset();
        } else if (inputx == -1) {
            cout << startAlphaBeta(game, inputy) << endl;
            cout << "Best Move : " << bestMove.x << ":" << bestMove.y << endl;
        } else {
            game.makeMove(Move(inputx, inputy));
            game.printBoard();
            if (game.gameEnded()) {
                cout << "Player: " << game.getWinner() << " won !" << endl;
                cout << "Enter -2 0 to restart." << endl;
            }
        }
    }

    return 0;
}
