#include <stdio.h>
#include "common.h"
#include "config.h"

int board_index(int x, int y) {
    return (y * LINE) + x;
}

/* Print board in terminal */
void show_board_terminal(int *board) {
    int x, y;

    printf("\n");
    for(y = 0; y < LINE; y++) {
        if((y > 0) && ((y % 3) == 0)) {
            printf("---------------------\n");
        }
        for(x = 0; x < LINE; x++) {
            if((x > 0) && ((x % 3) == 0)) {
                printf("| ");
            }
            printf("%d ", board[board_index(x, y)]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Reads a given file into a board */
int read_board_file(int *board, char *file_name) {
    FILE *board_file;
    int x, y, rc;

    board_file = fopen(file_name, "r");
    if(board_file == NULL) {
        printf("ERROR: could not open file: %s\n", file_name);
        return -1;
    }

    for(y = 0; y < LINE; y++) {
        for(x = 0; x < LINE; x++) {
            rc = fscanf(board_file, "%d", &board[board_index(x, y)]);
            if(rc == 0) {
                printf("File does not contain a full board\n");
                return -1;
            }
        }
    }

    // show_board_terminal(board);
    return 0;
}