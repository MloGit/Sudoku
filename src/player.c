#include <stdio.h>
#include <string.h>
#include "config.h"
#include "solver.h"
#include "generator.h"
#include "solver.h"
#include "check_board.h"

/*
 * Handles the commands of the game
 * 
 * Returns -1 if game should end.
 */
int do_command(char *command, int *board) {
    if(strcmp(command, "new") == 0) {
        generate_board(board, EMPTY_CELLS);
        memcpy(start_board, board, sizeof(int) * BOARD_SIZE);
    }
    else if(strcmp(command, "check") == 0) {
        if(check_board(board) == 0) {
            printf("Board is correct\n");
        }
        else {
            printf("Board is not correct\n");
            // QUESTION: Should this show which cells are incorrect?
        }
    }
    else if(strcmp(command, "solve") == 0) {
        if(solve_board(board, 0) == -1) {
            printf("Board breaks rules\n");
        }
    }
    else if(strcmp(command, "help") == 0) {
        printf("\nThis game has the following commands:\n");
        printf("new         generates new board\n");
        printf("enter (e)   starts a number entering\n");
        printf("check       checks if the board breaks any rules\n");
        printf("solve       solves the board\n");
        printf("quit (q)    quits the game\n");
    }
    else if(strcmp(command, "enter") == 0 || strcmp(command, "e") == 0) {
        return -1; // TODO: Implement
    }
    else if(strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
        return -1;
    }
    else {
        printf("Invalid command, you can use help to find valid commands\n");
    }

    return 0;
}
