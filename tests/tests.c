#include <stdio.h>
#include "../Unity/src/unity.h"
#include "../src/game_logic.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {
    TEST_ASSERT(1 == 1);
}

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

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    
    printf("\n");
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int valid_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            TEST_ASSERT_TRUE((board[i][j] >= 0) && (board[i][j] <= 9));
        }
    }


    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            TEST_ASSERT_FALSE(horizontal_duplicates(board, i, j));
            if(horizontal_duplicates(board, i, j)) {
                printf("\nHorizontal line %d contains duplicates", i+1);
                print_board(board);
                TEST_FAIL_MESSAGE("Horizontal duplicates found");
            }
            TEST_ASSERT_FALSE(vertical_duplicates(board, i, j));
            TEST_ASSERT_FALSE(box_duplicates(board, i, j));
        }
    }
    return 1;
}

void test_generate_board(void) {
    // TODO: Are my test cases too complex?
    // Yes, they are.
    int board[BOARD_SIZE][BOARD_SIZE];
    
    int board_sum = 5 * 9 * 9; // 5 * 9 equals the sum of 1 through 9

    generate_board(board);
    // TODO: The generator function (or a sub function) should create a board where every cell has a value.
    // This means that the sum of all the values is a constant (1*9 + 2*9 ...)
    TEST_ASSERT_TRUE(valid_board(board));
}

void test_solve_board(void) {
    TEST_ASSERT(1 == 2);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    RUN_TEST(test_generate_board);
    RUN_TEST(test_solve_board);
    return UNITY_END();
}