#include <stdio.h>
#include "check_board.h"
#include "check_cell.h"

int check_board(int board[LINE][LINE]) {
    int x, y;

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(board[x][y] == 0) {
                continue;
            }
            if(check_cell(board, x, y) == -1) {
                return -1;
            }
        }
    }
    
    return 0;
}