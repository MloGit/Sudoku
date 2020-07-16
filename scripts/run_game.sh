#!/bin/bash

cd "$(dirname "$0")" # Set cwd to /scripts
cd ../src/

gcc -o main main.c \
    player.c \
    solver.c \
    unique_solution.c \
    generator.c \
    check_cell.c \
    check_board.c \
    compare_boards.c \
    common.c \

./main
rm main