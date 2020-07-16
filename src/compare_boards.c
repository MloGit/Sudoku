#include <stdio.h>
#include "compare_boards.h"
#include "config.h"
#include "common.h"

/* Compare two boards. Returns 0 if they are equal, otherwise -1. */
int compare_boards(int *board_one, int *board_two) {
    int x, y;

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(board_one[board_index(x, y)] != board_two[board_index(x, y)]) {
                return -1;
            }
        }
    }
    return 0;
}