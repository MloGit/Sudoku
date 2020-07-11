#include <stdio.h>
#include <string.h>
#include "unique_solution.h"
#include "solver.h"

/* Checks that a board has only one unique solution */
int unique_solution(int board[LINE][LINE]) {
    int copy[LINE][LINE], second_copy[LINE][LINE];
    int x, y, rc;

    memcpy(copy, board, sizeof(int) * LINE * LINE);
    memcpy(second_copy, board, sizeof(int) * LINE * LINE);

    rc = solve_board(copy, 0);
    if(rc != 0) {
        return rc;
    }
    rc = solve_board(second_copy, 1);
    if(rc != 0) {
        return rc;
    }
    
    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(copy[x][y] != second_copy[x][y]) {
                return -1;
            }
        }
    }

    return 0;
}