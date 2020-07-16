#include <stdio.h>
#include "../vendor/ceedling/vendor/unity/src/unity.h"
#include "../../src/solver.h"
#include "../../src/config.h"
#include "../../src/common.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_solve_valid_board(void) {
    int board[BOARD_SIZE];
    int solution[BOARD_SIZE];
    char *board_names[3] =
        {"../../testing_boards/s03a.txt",
         "../../testing_boards/s07a.txt",
         "../../testing_boards/s10a.txt"};
    char *solution_names[3] =
        {"../../testing_boards/s03a_s.txt",
         "../../testing_boards/s07a_s.txt",
         "../../testing_boards/s10a_s.txt"};
    int i, rc;

    for(i = 0; i < 3; i++) {
        rc = read_board_file(board, board_names[i]);
        TEST_ASSERT(rc == 0);

        rc = solve_board(board, 0);
        TEST_ASSERT(rc == 0);

        rc = read_board_file(solution, solution_names[i]);
        TEST_ASSERT(rc == 0);

        TEST_ASSERT_EQUAL_INT_ARRAY(solution, board, LINE*LINE);
    }
}

/* 
 * Tests solver against three invalid boards.
 * Each board has one of the following problems:
 *   * Horizontal duplicate
 *   * Vertical duplicate
 *   * 3*3 box duplicate
 */
void test_solve_invalid_board(void) {
    int board[BOARD_SIZE];
    char *board_names[3] =
        {"../../testing_boards/invalid_s03a_1.txt",
         "../../testing_boards/invalid_s03a_2.txt",
         "../../testing_boards/invalid_s03a_3.txt"};
    int i, rc;

    for(i = 0; i < 3; i++) {
        rc = read_board_file(board, board_names[i]);
        TEST_ASSERT(rc == 0);

        rc = solve_board(board, 0);
        TEST_ASSERT(rc == -1);
    }
}

void main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_solve_valid_board);
    RUN_TEST(test_solve_invalid_board);
    UNITY_END();
}