#include <stdio.h>
#include "../vendor/ceedling/vendor/unity/src/unity.h"
#include "../../src/unique_solution.h"
#include "../../src/config.h"
#include "../../src/common.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_valid_unique_solution(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../../testing_boards/s03a.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(unique_solution(board) == 0);
}

void test_invalid_unique_solution(void) {
    int board[BOARD_SIZE] = {0};

    TEST_ASSERT(unique_solution(board) == -1);
}

void main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_unique_solution);
    RUN_TEST(test_invalid_unique_solution);
    UNITY_END();
}