#include <stdio.h>
#include "../vendor/ceedling/vendor/unity/src/unity.h"
#include "../../src/generator.h"
#include "../../src/solver.h"
#include "../../src/compare_boards.h"
#include "../../src/unique_solution.h"
#include "../../src/helper_functions.h"
#include "../../src/config.h"

void setUp(void) {
    init_generator();
}

void tearDown(void) {
}

void test_solvable_generate_board(void) {
    int board[BOARD_SIZE];
    int rc;

    generate_board(board, 45);
    rc = solve_board(board, 0);
    TEST_ASSERT_MESSAGE(rc == 0, "Could not solve generated board");
}

void test_unique_generate_board(void) {
    int board_one[BOARD_SIZE];
    int board_two[BOARD_SIZE];
    int i, x, y;

    generate_board(board_one, 45);
    generate_board(board_two, 45);

    TEST_ASSERT(compare_boards(board_one, board_two) == -1);
}

/* Tests that a generated board has only one unique solution */
void test_generate_board_unique_solution(void) {
    int board[BOARD_SIZE];

    generate_board(board, 45);
    TEST_ASSERT_MESSAGE(unique_solution(board) == 0,
                        "Generated board has multiple solutions");
}

void test_generate_board_has_correct_empty_cells(void) {
    int board[BOARD_SIZE];
    int x, y;
    int num_empty = 45, empty_counter = 0;

    generate_board(board, num_empty);
    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(board[board_index(x, y)] == 0) {
                empty_counter++;
            }
        }
    }
    
    TEST_ASSERT(empty_counter == num_empty);
}

void main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_solvable_generate_board);
    RUN_TEST(test_unique_generate_board);
    RUN_TEST(test_generate_board_unique_solution);
    RUN_TEST(test_generate_board_has_correct_empty_cells);
    UNITY_END();
}