#include <stdio.h>
#include "unity.h"
#include "generator.h"
#include "config.h"
#include "common.h"
#include "mock_solver.h"
#include "mock_unique_solution.h"

void setUp(void) {
    init_generator();
}

void test_generate_board(void) {
    int board[BOARD_SIZE];
    int zero_board[BOARD_SIZE] = {0};

    unique_solution_IgnoreAndReturn(0);

    solve_board_ExpectAndReturn(board, 0, 0);
    generate_board(board, 0);
    TEST_ASSERT_NOT_EMPTY(board);

    solve_board_ExpectAndReturn(board, 0, 0);
    // generate_board() fills, and empties, 3 diagonal 3*3 boxes
    generate_board(board, LINE * 3);
    TEST_ASSERT_EMPTY(board);
}