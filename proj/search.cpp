#include "search.h"
#include "helpfunctions.h"
#include "result.h"

int negamax(char current_player, char board[], int *best_move) {
    // check if the position is terminal
    char result = get_result(board);
    if (result != ' ') {
        if (result == current_player) return 1;
        if (result == 'd') return 0;
        return -1;
    }
    int evaluation = -2;
    int LBM; // local best move
    for (int i = 0; i<9; i++) {
        if (board[i] != ' ') continue;
        board[i] = current_player;
        int score = -negamax(other_player(current_player), board, best_move);
        board[i] = ' ';
        if (score > evaluation) {
            evaluation = score;
            LBM = i;
        }
    }
    *best_move = LBM;
    return evaluation;
}
