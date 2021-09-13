#ifndef HELP_FUNCTIONS_H
#include <string>
#define HELP_FUNCTIONS_H
bool try_to_end_game(char board[]);
void print_board(char *p);
int parse_move(std::string move_coordiantes);
char other_player(char a);
#endif
