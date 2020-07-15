#include <stdio.h>
#include <string.h>
#include "player.h"
#include "helper_functions.h"
#include "config.h"
#include "generator.h"
#include "solver.h"
#include "check_board.h"

/*
 * Handles the player commands in the game
 * 
 * Returns -1 if game should end.
 */
int do_command(char *command, int *board, int *start_board) {
    int str_size = 7;
    char str[str_size];
    int value, x, y;

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
        while(1) {
            printf("Enter cell value in format 'value x y': ");
            fgets(str, str_size, stdin);
            str[strcspn(str, "\n")] = '\0';
            if(str[0] == '\0') {
                printf("\nempty\n");
                break;
            }
            sscanf(str, "%d %d %d", &value, &x, &y);

            if(value > 9 || value < 1 || x > 9 || x < 1 || y > 9 || y < 1) {
                printf("Invalid input values, all must be in range 1-9\n");
            }
            else {
                if(start_board[board_index(x-1, y-1)] == 0) {
                    board[board_index(x-1, y-1)] = value;
                    break;
                }
                else {
                    printf("\n\nTried to set value of unmodifiable cell\n");
                }
            }
        }
    }
    else if(strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
        return -1;
    }
    else {
        printf("Invalid command, you can use help to find valid commands\n");
    }

    return 0;
}
