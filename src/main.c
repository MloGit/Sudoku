#include <stdio.h>
#include <string.h>
#include "config.h"
#include "player.h"
#include "generator.h"
#include "common.h"

void main() {
    /*
     * In loop:
     * Get input
     * Do command
     */

    int board[BOARD_SIZE] = {0};
    int start_board[BOARD_SIZE] = {0};
    char command[7];
    int run = 0;

    init_generator();    
    do_command("new", board, start_board);

    printf("Sudoku game\n");
    printf("Waiting for input ('enter' to modify cell, 'help', or 'quit')\n");

    while(run == 0) {
        printf(">>> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        run = do_command(command, board, start_board);
    }
}