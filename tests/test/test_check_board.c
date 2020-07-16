#include <stdio.h>
#include "unity.h"
#include "check_board.h"
#include "mock_check_cell.h"
#include "config.h"
#include "common.h"

void test_valid_check_board(void) {
    int board[BOARD_SIZE] = {0};

    check_cell_ExpectAndReturn(board, 0, 0, 0);
    check_cell_ExpectAndReturn(board, 4, 4, 0);
    check_cell_ExpectAndReturn(board, 8, 8, 0);

    board[board_index(0, 0)] = 9;
    board[board_index(4, 4)] = 5;
    board[board_index(8, 8)] = 1;

    TEST_ASSERT(check_board(board) == 0);
}

void test_invalid_check_board(void) {
    int board[BOARD_SIZE] = {0};

    check_cell_ExpectAndReturn(board, 0, 0, -1);
    check_cell_ExpectAndReturn(board, 4, 4, -1);
    check_cell_ExpectAndReturn(board, 8, 8, -1);

    board[board_index(0, 0)] = 9;

    TEST_ASSERT(check_board(board) == -1);

    board[board_index(0, 0)] = 0;
    board[board_index(4, 4)] = 5;

    TEST_ASSERT(check_board(board) == -1);

    board[board_index(4, 4)] = 0;
    board[board_index(8, 8)] = 1;

    TEST_ASSERT(check_board(board) == -1);
}