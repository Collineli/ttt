#include "result.h"

static char line_result(char board[], int a, int b, int c) {
    if (board[a] == ' ') return ' '; // no winner on this line
    if (board[a] != board[b]) return ' ';
    if (board[a] != board[c]) return ' ';
    return board[a];
}

char get_result(char board[]) {
    char w;
    // diagonals
    if ((w = line_result(board, 0, 4, 8)) != ' ') return w;
    if ((w = line_result(board, 2, 4, 6)) != ' ') return w;

    // horizontal
    if ((w = line_result(board, 0, 1, 2)) != ' ') return w;
    if ((w = line_result(board, 3, 4, 5)) != ' ') return w;
    if ((w = line_result(board, 6, 7, 8)) != ' ') return w;

    // vertical
    if ((w = line_result(board, 0, 3, 6)) != ' ') return w;
    if ((w = line_result(board, 1, 4, 7)) != ' ') return w;
    if ((w = line_result(board, 2, 5, 8)) != ' ') return w;

    // draw or not yet?
    for (int i = 0; i<9; i++) {
        if (board[i] == ' ') return ' ';
    }
    return 'd';
}
