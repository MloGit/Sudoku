#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "helper_functions.h"

void random_array(int *arr, int size);

/* Generates a sudoku board, empty cells contains zero. */
void generate_board(int board[LINE][LINE]) {
    int y, x, i, j, empty_count, temp_cell;
    int box[3*3], box_index;
    
    // Initialize all cells to zero
    for(i = 0; i < LINE; i++) {
        for(j = 0; j < LINE; j++) {
            board[j][i] = 0;
        }
    }

    // Set independent diagonal 3x3 boxes
    for(i = 0; i < LINE; i += 3) {
        random_array(box, 3*3);
        box_index = 0;
        for(y = i; y < i+3; y++) {
            for(x = i; x < i+3; x++) {
                board[x][y] = box[box_index];
                box_index++;
            }
        }
    }

    solve_board(board, 0);
    
    empty_count = 0;
    // TODO: Could this get stuck?
    // TODO: This would control difficulty a bit
    while(empty_count < 45) {
        x = (rand() % 9);
        y = (rand() % 9);
        if(board[x][y] == 0) {
            continue;
        }
        temp_cell = board[x][y];
        board[x][y] = 0;
        if(unique_solution(board) == 0) {
            empty_count++;
        }
        else {
            board[x][y] = temp_cell;
        }
    }
    // show_board_terminal(board);
}

void init_generator() {
    srand(time(0));
}

void random_array(int *arr, int size) {
    int i = 0, j;

    for(i = 0; i < size; i++) {
        arr[i] = (rand() % 9) + 1;
        for(j = 0; j < i; j++) {
            if(arr[j] == arr[i]) {
                i--;
                break;
            }
        }
    }
}

/* Checks that a board has only one unique solution */
int unique_solution(int board[LINE][LINE]) {
    int copy[LINE][LINE], second_copy[LINE][LINE];
    int x, y, rc;

    memcpy(copy, board, sizeof(int) * LINE * LINE);
    memcpy(second_copy, board, sizeof(int) * LINE * LINE);

    rc = solve_board(copy, 0);
    if(rc != 0) {
        return rc;
    }
    rc = solve_board(second_copy, 1);
    if(rc != 0) {
        return rc;
    }
    
    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(copy[x][y] != second_copy[x][y]) {
                return -1;
            }
        }
    }

    return 0;
}
