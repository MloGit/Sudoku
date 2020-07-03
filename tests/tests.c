#include <stdio.h>
#include "../Unity/src/unity.h"
#include "../src/solver.h"
#include "../src/generator.h"
#include "../src/helper_functions.h"

void setUp(void) {
    init_generator();
}

void tearDown(void) {
    // clean stuff up here
}

void test_valid_check_board(void) {
    int board[LINE][LINE];
    int rc;

    rc = read_board_file(board, "../tests/testing_boards/s03a_s.txt");
    TEST_ASSERT(rc == 0);

    // show_board_terminal(board);
    TEST_ASSERT(check_board(board) == 0);
}

void test_invalid_check_horizontal_duplicates(void) {
    int board[LINE][LINE];
    int rc;

    rc = read_board_file(board, "../tests/testing_boards/invalid_s03a_1.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_horizontal_duplicates(board, 5, 3) == -1);
}

void test_invalid_check_vertical_duplicates(void) {
    int board[LINE][LINE];
    int rc;

    rc = read_board_file(board, "../tests/testing_boards/invalid_s03a_3.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_vertical_duplicates(board, 2, 6) == -1);
}

void test_invalid_check_box_duplicates(void) {
    int board[LINE][LINE];
    int rc;

    rc = read_board_file(board, "../tests/testing_boards/invalid_s03a_2.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_box_duplicates(board, 4, 5) == -1);
}

void test_invalid_check_board(void) {
    int board[LINE][LINE];
    char *invalid_board_names[3] =
        {"../tests/testing_boards/invalid_s03a_1.txt",
         "../tests/testing_boards/invalid_s03a_2.txt",
         "../tests/testing_boards/invalid_s03a_3.txt"};
    int i, rc;

    for(i = 0; i < 3; i++) {
        rc = read_board_file(board, invalid_board_names[i]);
        TEST_ASSERT(rc == 0);
        // show_board_terminal(board);

        TEST_ASSERT(check_board(board) == -1);
    }
}

void test_solve_valid_board(void) {
    int board[LINE][LINE];
    int solution[LINE][LINE];
    char *board_names[3] =
        {"../tests/testing_boards/s03a.txt",
         "../tests/testing_boards/s07a.txt",
         "../tests/testing_boards/s10a.txt"};
    char *solution_names[3] =
        {"../tests/testing_boards/s03a_s.txt",
         "../tests/testing_boards/s07a_s.txt",
         "../tests/testing_boards/s10a_s.txt"};
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
    int board[LINE][LINE];
    char *board_names[3] =
        {"../tests/testing_boards/invalid_s03a_1.txt",
         "../tests/testing_boards/invalid_s03a_2.txt",
         "../tests/testing_boards/invalid_s03a_3.txt"};
    int i, rc;

    for(i = 0; i < 3; i++) {
        rc = read_board_file(board, board_names[i]);
        TEST_ASSERT(rc == 0);

        rc = solve_board(board, 0);
        TEST_ASSERT(rc == -1);
    }
}

void test_valid_unique_solution(void) {
    int board[LINE][LINE];
    int rc;

    rc = read_board_file(board, "../tests/testing_boards/s03a.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(unique_solution(board) == 0);
}

void test_invalid_unique_solution(void) {
    int board[LINE][LINE] = {0};

    TEST_ASSERT(unique_solution(board) == -1);
}

void test_solvable_generate_board(void) {
    int board[LINE][LINE];
    int rc;

    generate_board(board);
    rc = solve_board(board, 0);
    TEST_ASSERT_MESSAGE(rc == 0, "Could not solve generated board");
}

/* 
 * It is theretically possible for two identical boards to be generated, so it 
 * loops through five generated boards, and fails the test only if all of them 
 * are identical.
 */
void test_unique_generate_board(void) {
    int board[LINE][LINE];
    int different_board[LINE][LINE];
    int i, x, y;

    generate_board(board);

    for(i = 0; i < 5; i++) {
        generate_board(different_board);
        for(y = 0; y < LINE; y++) {
            for(x = 0; x < LINE; x++) {
                if(board[x][y] != different_board[x][y]) {
                    TEST_PASS();
                }
            }
        }
    }

    TEST_FAIL_MESSAGE("Generated boards are not different");
}

/* Tests that a generated board has only one unique solution */
void test_generate_board_unique_solution(void) {
    int board[LINE][LINE];

    generate_board(board);
    TEST_ASSERT_MESSAGE(unique_solution(board) == 0,
                        "Generated board has multiple solutions");
}

void test_generate_board_has_empty_cells(void) {
    int board[LINE][LINE];
    int x, y;

    generate_board(board);
    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(board[x][y] == 0) {
                TEST_PASS();
            }
        }
    }
    TEST_FAIL_MESSAGE("Generated board has no empty cells");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_valid_check_board);
    RUN_TEST(test_invalid_check_horizontal_duplicates);
    RUN_TEST(test_invalid_check_vertical_duplicates);
    RUN_TEST(test_invalid_check_box_duplicates);
    RUN_TEST(test_invalid_check_board);
    RUN_TEST(test_solve_valid_board);
    RUN_TEST(test_solve_invalid_board);
    RUN_TEST(test_valid_unique_solution);
    RUN_TEST(test_invalid_unique_solution);
    RUN_TEST(test_solvable_generate_board);
    RUN_TEST(test_unique_generate_board);
    RUN_TEST(test_generate_board_unique_solution);
    RUN_TEST(test_generate_board_has_empty_cells);
    return UNITY_END();
}