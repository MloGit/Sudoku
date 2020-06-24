#include <stdio.h>
#include "CUnit/Basic.h"
#include "game_logic.h"

/* Tests the horizontal line (y) of the cell (x, y) */
int horizontal_duplicates(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    int i;
   
    for(i = 0; i < BOARD_SIZE; i++) {
        if(board[i][y] == 0 || i == x) { /* Ignore zero and self */
            i++;
        }
        if(board[i][y] == board[x][y]) {
            return 1;
        }
    }
    return 0;
}

/* Tests the vertical line (x) of the cell (x, y) */
int vertical_duplicates(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    int i;
   
    for(i = 0; i < BOARD_SIZE; i++) {
        if(board[x][i] == 0 || i == y) { /* Ignore zero and self */
            i++;
        }
        if(board[x][i] == board[x][y]) {
            return 1;
        }
    }
    return 0;
}

/* Tests the 3x3 box which the cell (x, y) resides in */
int box_duplicates(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    int i, j;
    int box_start;

    box_start = (x / 3) * 3;

    for(i = box_start; i < (box_start + 3); i++) {
        for(j = box_start; j < (box_start + 3); j++) {
            /* Ignore zero and self */
            if((i == x && j == y) || board[i][j] == 0) {
                j++;
            }
            if(board[i][j] == board[x][y]) {
                return 1;
            }
        }
    }
    return 0;
}

int valid_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            CU_ASSERT((board[i][j] >= 0) && (board[i][j] <= 9));
        }
    }

    if(CU_get_error() == 0) {
        CU_FAIL("Cell(s) have invalid values");
        return 0;
    }

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            CU_ASSERT_FALSE(horizontal_duplicates(board, i, j));
            CU_ASSERT_FALSE(vertical_duplicates(board, i, j));
            CU_ASSERT_FALSE(box_duplicates(board, i, j));
        }
    }

    return 1;
}

void test_generate_board(void) {
    int board[BOARD_SIZE][BOARD_SIZE];

    generate_board(board);
    CU_ASSERT_TRUE(valid_board(board));
    /* Tests valid numbers, and board rules */
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite, "test of ()", test_generate_board)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}