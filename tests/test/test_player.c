#include <stdio.h>
#include <string.h>
#include "unity.h"
#include "player.h"
#include "config.h"
#include "mock_generator.h"
#include "mock_check_board.h"
#include "mock_solver.h"

/*
 * This test should:
 * 
 * Test for correct input format, and illegal inputs.
 * Test help command and every command linked to in help.
 *   new (generate new board)
 *   enter (e)
 *   check
 *   solve
 *   quit (q)
 * Test what happens when board is complete (game won).
 */

void test_do_command(void) {
    int board[BOARD_SIZE] = {0};
    int start_board[BOARD_SIZE] = {0};
    
    // Now board and start_board are different
    start_board[board_index(4, 5)] = 5;
    generate_board_ExpectAnyArgs();
    TEST_ASSERT_MESSAGE(do_command("new", board, start_board) == 0,
                        "new failed");
    TEST_ASSERT_EQUAL_INT_ARRAY(board, start_board, BOARD_SIZE);
    
    check_board_ExpectAndReturn(board, 0);
    TEST_ASSERT_MESSAGE(do_command("check", board, board) == 0, "check failed");

    solve_board_ExpectAndReturn(board, 0, 0);
    TEST_ASSERT_MESSAGE(do_command("solve", board) == 0, "solve failed");

    TEST_ASSERT_MESSAGE(do_command("help", board) == 0, "help failed");
    TEST_ASSERT_MESSAGE(do_command("enter", board) == 0, "enter failed");
    TEST_ASSERT_MESSAGE(do_command("e", board) == 0, "e (enter) failed");
    TEST_ASSERT_MESSAGE(do_command("quit", board) == -1, "quit failed");
    TEST_ASSERT_MESSAGE(do_command("q", board) == -1, "q (quit) failed");
}