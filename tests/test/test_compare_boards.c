#include <stdio.h>
#include "unity.h"
#include "compare_boards.h"
#include "config.h"
#include "helper_functions.h"

void test_compare_boards(void) {
    int board_one[BOARD_SIZE] = {0};
    int board_two[BOARD_SIZE] = {0};

    TEST_ASSERT(compare_boards(board_one, board_two) == 0);
}

void test_compare_different_boards(void) {
    int board_one[BOARD_SIZE] = {0};
    int board_two[BOARD_SIZE] = {0};

    board_two[board_index(8, 8)] = 9;

    TEST_ASSERT(compare_boards(board_one, board_two) == -1);
    
    board_two[board_index(8, 8)] = 0;
    board_two[board_index(0, 0)] = 9;

    TEST_ASSERT(compare_boards(board_one, board_two) == -1);
}