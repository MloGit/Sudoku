#include <stdio.h>
#include "unique_solution.h"
#include "config.h"
#include "common.h"
#include "mock_solver.h"
#include "mock_compare_boards.h"

void test_valid_unique_solution(void) {
    int board[BOARD_SIZE] = {0};

    solve_board_ExpectAndReturn(board, 0, 0);
    solve_board_ExpectAndReturn(board, 1, 0);
    compare_boards_ExpectAndReturn(board, board, 0);

    TEST_ASSERT(unique_solution(board) == 0);
}

void test_invalid_solve_unique_solution(void) {
    int board[BOARD_SIZE] = {0};

    solve_board_ExpectAndReturn(board, 0, -1);

    TEST_ASSERT(unique_solution(board) == -1);

    solve_board_ExpectAndReturn(board, 0, 0);
    solve_board_ExpectAndReturn(board, 1, -1);

    TEST_ASSERT(unique_solution(board) == -1);
}

void test_not_unique_solution(void) {
    int board[BOARD_SIZE] = {0};
    
    solve_board_ExpectAndReturn(board, 0, 0);
    solve_board_ExpectAndReturn(board, 1, 0);
    compare_boards_ExpectAndReturn(board, board, -1);

    TEST_ASSERT(unique_solution(board) == -1);
}