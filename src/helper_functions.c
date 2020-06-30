#include <stdio.h>
#include "helper_functions.h"

void show_board_terminal(int board[LINE][LINE]) {
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
            printf("%d ", board[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}