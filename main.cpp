#include <iostream>
#include <vector>
#include "TicTacToe.h"

using namespace std;

vector<Move> generateMoves(TicTacToe& game) {
    vector<Move> returnVector = vector<Move>();
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (game.getShape(row, col) == SHAPE_EMPTY) {
                returnVector.push_back(Move(row, col));
            }
        }
    }

    return returnVector;
}

Move bestMove {0, 0};

int alphaBeta(TicTacToe& game, int alpha, int beta, int depth, Player player) {
    if (depth == 0 || game.gameEnded()) {
        return game.getScore(player);
    }

    for (Move move : generateMoves(game)) {
        game.makeMove(move);
        int score = -alphaBeta(game, -beta, -alpha, depth - 1, notPlayer(player));
        game.undoMove(move);
        if(score >= beta)
            return beta;
        else if(score > alpha) {
            alpha = score;
            bestMove = move;
        }
    }
    return alpha;
}

int startAlphaBeta(TicTacToe& game, int depth) {
    cout << "Best Move : " << bestMove.x << ":" << bestMove.y << endl;
    return alphaBeta(game, -999, 999, depth, game.getTurn());
}

int main(int argc, char const *argv[])
{
    cout << "Started !" << endl;

    TicTacToe game = TicTacToe();

    for (int input; cin >> input;) {
        if (input < 0) {
            cout << startAlphaBeta(game, -input) << endl;
        } else {
            game.makeMove(Move(input / 3, input % 3));
            game.printBoard();
            if (game.gameEnded()) {
                cout << game.getWinner() << endl;
                break;
            }
        }
    }

    return 0;
}
