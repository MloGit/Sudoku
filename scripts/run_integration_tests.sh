#!/bin/bash

function wait_for_user() {
    echo ""
    read -p "Press any key to continue... (or q to quit)" -n1 -s status
    if [[ $status == "q" ]]; then
        exit
    fi
    echo ""
    echo ""
}

cd "$(dirname "$0")" # Set cwd to /scripts
cd ../tests/integration_tests

echo "These tests are hierarchical, so if the top one fails then the lower ones
will fail or give false positives."

wait_for_user

gcc -o integration_test_solver integration_test_solver.c \
    ../../src/solver.c \
    ../../src/check_board.c \
    ../../src/check_cell.c \
    ../../src/common.c \
    ../vendor/ceedling/vendor/unity/src/unity.c

./integration_test_solver
rm integration_test_solver

wait_for_user

gcc -o integration_test_unique_solution integration_test_unique_solution.c \
    ../../src/unique_solution.c \
    ../../src/compare_boards.c \
    ../../src/solver.c \
    ../../src/check_board.c \
    ../../src/check_cell.c \
    ../../src/common.c \
    ../vendor/ceedling/vendor/unity/src/unity.c

./integration_test_unique_solution
rm integration_test_unique_solution

wait_for_user

gcc -o integration_test_generator integration_test_generator.c \
    ../../src/generator.c \
    ../../src/unique_solution.c \
    ../../src/compare_boards.c \
    ../../src/solver.c \
    ../../src/check_board.c \
    ../../src/check_cell.c \
    ../../src/common.c \
    ../vendor/ceedling/vendor/unity/src/unity.c

./integration_test_generator
rm integration_test_generator