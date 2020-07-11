#include <stdio.h>
#include "check_cell.h"
#include "helper_functions.h"

/* Checks the horizontal line (y) of the cell (x, y) */
int check_horizontal_duplicates(int *board, int x, int y) {
    int i_x;

    for(i_x = 0; i_x < LINE; i_x++) {
        // Ignore zero and (x, y)
        if(board[board_index(i_x, y)] == 0 || i_x == x) {
            continue;
        }
        if(board[board_index(i_x, y)] == board[board_index(x, y)]) {
            return -1;
        }
    }
    return 0;
}

/* Checks the vertical line (x) of the cell (x, y) */
int check_vertical_duplicates(int *board, int x, int y) {
    int i_y;

    for(i_y = 0; i_y < LINE; i_y++) {
        // Ignore zero and (x, y)
        if(board[board_index(x, i_y)] == 0 || i_y == y) {
            continue;
        }
        if(board[board_index(x, i_y)] == board[board_index(x, y)]) {
            return -1;
        }
    }
    return 0;
}

/* Checks the 3x3 box which the cell (x, y) resides in */
int check_box_duplicates(int *board, int x, int y) {
    int i_x, i_y;
    int box_start_x, box_start_y;

    box_start_x = (x / 3) * 3;
    box_start_y = (y / 3) * 3;

    for(i_y = box_start_y; i_y < (box_start_y + 3); i_y++) {
        for(i_x = box_start_x; i_x < (box_start_x + 3); i_x++) {
            // Ignore zero and (x, y)
            if(board[board_index(i_x, i_y)] == 0 || (i_y == y && i_x == x)) {
                continue;
            }
            if(board[board_index(i_x, i_y)] == board[board_index(x, y)]) {
                return -1;
            }
        }
    }
    return 0;
}

int check_cell(int *board, int x, int y) {
    if(board[board_index(x, y)] < 0 || board[board_index(x, y)] > 9) {
        return -1;
    }

    if(check_horizontal_duplicates(board, x, y) == -1) {
        // printf("Horizontal rule broken with cell: (%d, %d)\n", x+1, y+1);
        return -1;
    }
    if(check_vertical_duplicates(board, x, y) == -1) {
        // printf("Vertical rule broken with cell: (%d, %d)\n", x+1, y+1);
        return -1;
    }
    if(check_box_duplicates(board, x, y) == -1) {
        // printf("3*3 box rule broken with cell: (%d, %d)\n", x+1, y+1);
        return -1;
    }

    return 0;
}