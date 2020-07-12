#include <stdio.h>
#include "unity.h"
#include "check_cell.h"
#include "helper_functions.h"

void test_invalid_check_horizontal_duplicates(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/invalid_s03a_1.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_horizontal_duplicates(board, 5, 3) == -1);
}

void test_valid_check_horizontal_duplicates(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/s03a_s.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_horizontal_duplicates(board, 5, 3) == 0);
}

void test_invalid_check_vertical_duplicates(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/invalid_s03a_3.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_vertical_duplicates(board, 2, 6) == -1);
}

void test_valid_check_vertical_duplicates(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/s03a_s.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_vertical_duplicates(board, 2, 6) == 0);
}

void test_invalid_check_box_duplicates(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/invalid_s03a_2.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_box_duplicates(board, 4, 5) == -1);
}

void test_valid_check_box_duplicates(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/s03a_s.txt");
    TEST_ASSERT(rc == 0);

    TEST_ASSERT(check_box_duplicates(board, 4, 5) == 0);
}

void test_invalid_values_check_cell(void) {
    int board[BOARD_SIZE];
    int rc;

    rc = read_board_file(board, "../testing_boards/s03a_s.txt");
    TEST_ASSERT(rc == 0);

    board[board_index(6, 3)] = 15;
    board[board_index(2, 7)] = -2;

    TEST_ASSERT(check_cell(board, 6, 3) == -1);
    TEST_ASSERT(check_cell(board, 2, 7) == -1);
}