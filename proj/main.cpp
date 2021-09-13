#include <iostream>
#include <string>
#include "search.h"
#include "helpfunctions.h"

int main()
{
    char board[] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    std::cout << "Choose player (X or O): ";
    char player = ' ';
    while (player != 'X' && player != 'O') {
        std::cin >> player;
        if (player != 'X' && player != 'O') {
            std::cout << "Invalid option. Please choose X or O:\n";
        }
    }

    char computer_player = other_player(player);

    if (player == 'O') {
        int computer_move;
        negamax(computer_player, board, &computer_move);
        board[computer_move] = computer_player;
    }

    std::cin.ignore();
    while(true) {
        print_board(board);
        std::cout << "Please enter a move (for example a1): ";
        int move_index;
        while(true) {
            std::string move;
            std::getline(std::cin, move);
            move_index = parse_move(move);
            if (move_index == -1) {
                std::cout << "Invalid move. Please enter a valid move (for example a1): ";
            } else if (board[move_index] != ' ') {
                std::cout << "The cell is not empty. Please choose another move: ";
            } else {
                break;
            }
        }
        board[move_index] = player;

        if (try_to_end_game(board)) return 0;

        int computer_move;
        negamax(computer_player, board, &computer_move);
        board[computer_move] = computer_player;

        if (try_to_end_game(board)) return 0;
    }
}
