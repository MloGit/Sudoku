#ifndef SOLVER_H
#define SOLVER_H

#define LINE 9

int solve_board(int board[LINE][LINE], int backwards);
int check_horizontal_duplicates(int board[LINE][LINE], int x, int y);
int check_vertical_duplicates(int board[LINE][LINE], int x, int y);
int check_box_duplicates(int board[LINE][LINE], int x, int y);
int check_cell(int board[LINE][LINE], int x, int y);
int check_board(int board[LINE][LINE]);

#endif