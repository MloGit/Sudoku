#include <stdio.h>
#include <string.h>
#include "unique_solution.h"
#include "compare_boards.h"
#include "solver.h"
#include "config.h"
#include "common.h"

/* Checks that a board has only one unique solution */
int unique_solution(int *board) {
    int copy[BOARD_SIZE], second_copy[BOARD_SIZE];
    int x, y, rc;

    memcpy(copy, board, sizeof(int) * BOARD_SIZE);
    memcpy(second_copy, board, sizeof(int) * BOARD_SIZE);

    rc = solve_board(copy, 0); // Solve normal
    if(rc != 0) {
        return rc;
    }
    rc = solve_board(second_copy, 1); // Solve backwards
    if(rc != 0) {
        return rc;
    }
    
    // If normal and backwards are not equal, then there are multiple solutions
    if(compare_boards(copy, second_copy) != 0) {
        return -1;
    }

    return 0;
}