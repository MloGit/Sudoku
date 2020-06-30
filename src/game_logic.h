#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#define BOARD_SIZE 9

void generate_board(int board[BOARD_SIZE][BOARD_SIZE]);
int check_cell(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
int solve_board(int board[BOARD_SIZE][BOARD_SIZE]);

#endif