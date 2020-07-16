#include <stdio.h>
#include <string.h>
#include "solver.h"
#include "check_cell.h"
#include "check_board.h"
#include "config.h"
#include "common.h"

int _solve_board(int *board, int x, int y, int backwards);

/*
 * Solves a given sudoku board
 * 
 * Backwards argument allows for checking that there is only one solution.
 * It starts by filling cells with 9 and then decrements the test number,
 * instead of starting with 1 and incrementing.
 * 
 * Returns -1 on invalid boards.
 */
int solve_board(int *board, int backwards) {
    if(check_board(board) == -1) {
        return -1;
    }
    return _solve_board(board, 0, 0, backwards);
}

int _solve_board(int *board, int x, int y, int backwards) {
    int valid, rc, i;

    if(x == LINE) {
        x = 0;
        y++;
    }
    if(y == LINE) {
        return 0;
    }

    if(board[board_index(x, y)] == 0) {
        for(i = 1; i <= 9; i++) {
            if(backwards) {
                board[board_index(x, y)] = 10-i;
            }
            else {
                board[board_index(x, y)] = i;
            }
            
            if(check_cell(board, x, y) == 0) {
                rc = _solve_board(board, x+1, y, backwards);
                if(rc != -1) {
                    return rc;
                }
            }
        }
        // Starts backtracking here if no valid cell value is found.
        board[board_index(x, y)] = 0;
        return -1;
    }
    else {
        return _solve_board(board, x+1, y, backwards);
    }
}