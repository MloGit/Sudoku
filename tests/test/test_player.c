#include <stdio.h>
#include <string.h>
#include "unity.h"
#include "player.h"
#include "config.h"
#include "common.h"
#include "mock_generator.h"
#include "mock_check_board.h"
#include "mock_solver.h"

void setUp(void) {
    FILE *fp;

    fp = fopen("test/player_input_for_tests.txt", "w");
    TEST_ASSERT(fp != NULL);

    fputs("\n", fp); // 1. do_command() call in enter test
    fputs("\n", fp); // 2. do_command() call in enter test
    fputs("1 1 1\n", fp); // 3. do_command() call in enter test

    fputs("1 7 1\n", fp); // 1. do_command() call in invalid enter test
    fputs("\n", fp); // Make 1. do_command() call exit from "enter" operation
    
    fclose(fp);
}

void test_do_command(void) {
    int board[BOARD_SIZE] = {0};
    int start_board[BOARD_SIZE] = {0};
    
    // Make board and start_board different
    start_board[board_index(4, 5)] = 5;
    generate_board_ExpectAnyArgs();
    TEST_ASSERT_MESSAGE(do_command("new", board, start_board) == 0,
                        "new failed");
    // After "new" board and start_board should be equal
    TEST_ASSERT_EQUAL_INT_ARRAY(board, start_board, BOARD_SIZE);
    
    check_board_ExpectAndReturn(board, 0);
    TEST_ASSERT_MESSAGE(do_command("check", board, board) == 0, "check failed");

    solve_board_ExpectAndReturn(board, 0, 0);
    TEST_ASSERT_MESSAGE(do_command("solve", board, board) == 0, "solve failed");

    TEST_ASSERT_MESSAGE(do_command("help", board, board) == 0, "help failed");

    TEST_ASSERT_MESSAGE(do_command("quit", board, board) == -1, "quit failed");
    TEST_ASSERT_MESSAGE(do_command("q", board, board) == -1, "q (quit) failed");
}

void test_do_command_enter(void) {
    int board[BOARD_SIZE] = {0};

    // Empty input should stop enter operation
    TEST_ASSERT(do_command("enter", board, board) == 0);
    TEST_ASSERT(do_command("e", board, board) == 0);

    // Sets first cell, see setUp()
    TEST_ASSERT(do_command("enter", board, board) == 0);
    TEST_ASSERT(board[board_index(0, 0)] == 1);
}

void test_do_command_invalid_enter(void) {
    int board[BOARD_SIZE] = {0};
    int start_board[BOARD_SIZE] = {0};
    FILE *fp;

    start_board[board_index(6, 0)] = 5;

    // Tries to set (6, 0) cell (see setUp line 21)
    TEST_ASSERT(do_command("e", board, start_board) == 0);
    // Refuses to change cell since it is non-zero in start board
    TEST_ASSERT(board[board_index(6, 0)] == 0);
}