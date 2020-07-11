#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "config.h"

void show_board_terminal(int board[LINE][LINE]);
int read_board_file(int board[LINE][LINE], char *file_name);

#endif