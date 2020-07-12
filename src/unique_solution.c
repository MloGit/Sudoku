#include <stdio.h>
#include <string.h>
#include "unique_solution.h"
#include "compare_boards.h"
#include "helper_functions.h"
#include "solver.h"

/* Checks that a board has only one unique solution */
int unique_solution(int *board) {
    int copy[BOARD_SIZE], second_copy[BOARD_SIZE];
    int x, y, rc;

    memcpy(copy, board, sizeof(int) * BOARD_SIZE);
    memcpy(second_copy, board, sizeof(int) * BOARD_SIZE);

    rc = solve_board(copy, 0);
    if(rc != 0) {
        return rc;
    }
    rc = solve_board(second_copy, 1);
    if(rc != 0) {
        return rc;
    }
    
    if(compare_boards(copy, second_copy) != 0) {
        return -1;
    }

    return 0;
}