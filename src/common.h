#ifndef COMMON_H
#define COMMON_H

int board_index(int x, int y);
void show_board_terminal(int *board);
int read_board_file(int *board, char *file_name);

#endif