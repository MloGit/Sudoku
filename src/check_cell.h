#ifndef CHECK_CELL_H
#define CHECK_CELL_H

int check_horizontal_duplicates(int *board, int x, int y);
int check_vertical_duplicates(int *board, int x, int y);
int check_box_duplicates(int *board, int x, int y);
int check_cell(int *board, int x, int y);

#endif