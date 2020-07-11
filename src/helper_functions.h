#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "config.h"

int board_index(int x, int y);
void show_board_terminal(int *board);
int read_board_file(int *board, char *file_name);

#endif