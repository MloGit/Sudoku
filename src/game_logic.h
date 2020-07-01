#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#define LINE 9

void generate_board(int board[LINE][LINE]);
int check_horizontal_duplicates(int board[LINE][LINE], int x, int y);
int check_vertical_duplicates(int board[LINE][LINE], int x, int y);
int check_box_duplicates(int board[LINE][LINE], int x, int y);
int check_cell(int board[LINE][LINE], int x, int y);
int check_board(int board[LINE][LINE]);
int solve_board(int board[LINE][LINE], int backwards);
int unique_solution(int board[LINE][LINE]);

#endif