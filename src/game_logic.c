#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"
#include "helper_functions.h"

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
    show_board_terminal(board);
}

/* Checks the horizontal line (y) of the cell (x, y) */
int check_horizontal_duplicates(int board[LINE][LINE], int x, int y) {
    int i_x;

    for(i_x = 0; i_x < LINE; i_x++) {
        if(board[i_x][y] == 0 || i_x == x) { // Ignore zero and (x, y)
            continue;
        }
        if(board[i_x][y] == board[x][y]) {
            return -1;
        }
    }
    return 0;
}

/* Checks the vertical line (x) of the cell (x, y) */
int check_vertical_duplicates(int board[LINE][LINE], int x, int y) {
    int i_y;

    for(i_y = 0; i_y < LINE; i_y++) {
        if(board[x][i_y] == 0 || i_y == y) { // Ignore zero and (x, y)
            continue;
        }
        if(board[x][i_y] == board[x][y]) {
            return -1;
        }
    }
    return 0;
}

/* Checks the 3x3 box which the cell (x, y) resides in */
int check_box_duplicates(int board[LINE][LINE], int x, int y) {
    int i_x, i_y;
    int box_start_x, box_start_y;

    box_start_x = (x / 3) * 3;
    box_start_y = (y / 3) * 3;

    for(i_y = box_start_y; i_y < (box_start_y + 3); i_y++) {
        for(i_x = box_start_x; i_x < (box_start_x + 3); i_x++) {
            // Ignore zero and (x, y)
            if(board[i_x][i_y] == 0 || (i_y == y && i_x == x)) {
                continue;
            }
            if(board[i_x][i_y] == board[x][y]) {
                return -1;
            }
        }
    }
    return 0;
}

int check_cell(int board[LINE][LINE], int x, int y) {
    if(check_horizontal_duplicates(board, x, y) == -1) {
        // printf("Horizontal rule broken with cell: (%d, %d)\n", x+1, y+1);
        return -1;
    }
    if(check_vertical_duplicates(board, x, y) == -1) {
        // printf("Vertical rule broken with cell: (%d, %d)\n", x+1, y+1);
        return -1;
    }
    if(check_box_duplicates(board, x, y) == -1) {
        // printf("3*3 box rule broken with cell: (%d, %d)\n", x+1, y+1);
        return -1;
    }

    return 0;
}

int check_board(int board[LINE][LINE]) {
    int x, y;

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            if(board[x][y] == 0) {
                continue;
            }
            if(check_cell(board, x, y) == -1) {
                return -1;
            }
        }
    }
    
    return 0;
}

int _solve_board(int board[LINE][LINE], int x, int y, int backwards) {
    int valid, rc, i;

    if(x == LINE) {
        x = 0;
        y++;
    }
    if(y == LINE) {
        return 0;
    }

    if(board[x][y] == 0) {
        for(i = 1; i <= 9; i++) {
            if(backwards) {
                board[x][y] = 10-i;
            }
            else {
                board[x][y] = i;
            }
            
            if(check_cell(board, x, y) == 0) {
                rc = _solve_board(board, x+1, y, backwards);
                if(rc != -1) {
                    return rc;
                }
            }
        }
        board[x][y] = 0;
        return -1;
    }
    else {
        return _solve_board(board, x+1, y, backwards);
    }
}

/*
 * Solves a given sudoku board
 * 
 * Backwards argument allows for checking that there is only one solution.
 */
int solve_board(int board[LINE][LINE], int backwards) {
    if(check_board(board) == -1) {
        return -1;
    }
    return _solve_board(board, 0, 0, backwards);
}
