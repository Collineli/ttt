#include <iostream>
#include "helpfunctions.h"
#include "result.h"

bool try_to_end_game(char board[]) {
    char res;
    if ((res = get_result(board)) != ' ') {
        std::cout << "Game over!\nResult: ";
        if (res == 'd') {
            std::cout << "draw.\n";
        } else {
            std::cout << res << " won the game.\n";
        }
        print_board(board);
        return true;
    }
    return false;
}

void print_board(char *p) {
    std::cout << "+-+-+-+\n";
    for (int i = 3; i>0; i--) {
        for (int j = 0; j<3; j++) {
            std::cout << "|" << *p++;
        }
        std::cout << "| " << i << "\n";
        std::cout << "+-+-+-+\n";
    }
    std::cout << " a b c\n";
}

int parse_move(std::string move_coordiantes) { // e.g. "a1" -> 6
    int number = move_coordiantes[1] - '0';
    if (number < 1 || number > 3) {
        return -1;
    }

    char letter = move_coordiantes[0];
    int c;
    switch (letter) { // int c = letter-'a' would work on most machines
        case 'a':     // but C++ standard doesn't guarantee that.
            c = 0;
            break;
        case 'b':
            c = 1;
            break;
        case 'c':
            c = 2;
            break;
        default:
            return -1;
    }

    return (3-number)*3+c;
}

char other_player(char a) {
    switch (a) {
        case 'X': return 'O';
        case 'O': return 'X';
    }
}
