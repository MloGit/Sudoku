#include <stdio.h>
#include "helper_functions.h"

void show_board_terminal(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    printf("\n");
    for(i = 0; i < 9; i++) {
        if((i > 0) && ((i % 3) == 0)) {
            printf("---------------------\n");
        }
        for(j = 0; j < 9; j++) {
            if((j > 0) && ((j % 3) == 0)) {
                printf("| ");
            }
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}