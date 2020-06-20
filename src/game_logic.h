#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#define BOARD_SIZE 9

void generate_board(int board[BOARD_SIZE][BOARD_SIZE]);
int solve_board(int board[BOARD_SIZE][BOARD_SIZE]);
void show_board_terminal(int board[BOARD_SIZE][BOARD_SIZE]);

#endif