#include <stdio.h>
#include "check_board.h"
#include "check_cell.h"
#include "helper_functions.h"

int check_board(int *board) {
    int x, y;

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(board[board_index(x, y)] == 0) {
                continue;
            }
            if(check_cell(board, x, y) == -1) {
                return -1;
            }
        }
    }
    
    return 0;
}