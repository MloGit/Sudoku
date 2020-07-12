/*
 * Unit tests for solver
 * 
 * Only needs a valid test, since check_board() asserts that board is solvable
 * and that means the algorithm of solve_board() never has to deal with an
 * unsolvable board.
 */

#include <stdio.h>
#include "solver.h"
#include "helper_functions.h"
#include "mock_check_cell.h"
#include "mock_check_board.h"

void test_solve_board(void) {
    int board[BOARD_SIZE] = {0};
    int y, x;

    check_board_IgnoreAndReturn(0);

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            check_cell_ExpectAndReturn(board, x, y, 0);
        }
    }
    
    TEST_ASSERT(solve_board(board, 0) == 0);
}

void test_solve_board_backwards(void) {
    int board[BOARD_SIZE] = {0};
    int y, x;

    check_board_IgnoreAndReturn(0);

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            check_cell_ExpectAndReturn(board, x, y, 0);
        }
    }
    
    TEST_ASSERT(solve_board(board, 1) == 0);
}