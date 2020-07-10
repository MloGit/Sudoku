#include "build/temp/_test_all.c"
#include "../src/helper_functions.h"
#include "../src/generator.h"
#include "../src/solver.h"
#include "/home/magnus/Dropbox/it/portfolio/sudoku_game/tests/vendor/ceedling/vendor/unity/src/unity.h"


void setUp(void) {

    init_generator();

}











void test_invalid_check_horizontal_duplicates(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/invalid_s03a_1.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(20)));}} while(0);



    do {if ((check_horizontal_duplicates(board, 5, 3) == -1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(22)));}} while(0);

}



void test_valid_check_horizontal_duplicates(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/s03a_s.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));}} while(0);



    do {if ((check_horizontal_duplicates(board, 5, 3) == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(32)));}} while(0);

}



void test_invalid_check_vertical_duplicates(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/invalid_s03a_3.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(40)));}} while(0);



    do {if ((check_vertical_duplicates(board, 2, 6) == -1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(42)));}} while(0);

}



void test_valid_check_vertical_duplicates(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/s03a_s.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(50)));}} while(0);



    do {if ((check_vertical_duplicates(board, 2, 6) == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(52)));}} while(0);

}



void test_invalid_check_box_duplicates(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/invalid_s03a_2.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(60)));}} while(0);



    do {if ((check_box_duplicates(board, 4, 5) == -1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(62)));}} while(0);

}



void test_valid_check_box_duplicates(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/s03a_s.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);



    do {if ((check_box_duplicates(board, 4, 5) == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

}



void test_valid_check_board(void) {

    int board[9][9];

    int rc;







    rc = read_board_file(board, "../testing_boards/s03a_s.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(82)));}} while(0);





    do {if ((check_board(board) == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(85)));}} while(0);

}



void test_invalid_check_board(void) {

    int board[9][9];

    char *invalid_board_names[3] =

        {"../testing_boards/invalid_s03a_1.txt",

         "../testing_boards/invalid_s03a_2.txt",

         "../testing_boards/invalid_s03a_3.txt"};

    int i, rc;



    for(i = 0; i < 3; i++) {

        rc = read_board_file(board, invalid_board_names[i]);

        do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(98)));}} while(0);





        do {if ((check_board(board) == -1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(101)));}} while(0);

    }

}



void test_solve_valid_board(void) {

    int board[9][9];

    int solution[9][9];

    char *board_names[3] =

        {"../testing_boards/s03a.txt",

         "../testing_boards/s07a.txt",

         "../testing_boards/s10a.txt"};

    char *solution_names[3] =

        {"../testing_boards/s03a_s.txt",

         "../testing_boards/s07a_s.txt",

         "../testing_boards/s10a_s.txt"};

    int i, rc;



    for(i = 0; i < 3; i++) {

        rc = read_board_file(board, board_names[i]);

        do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(120)));}} while(0);



        rc = solve_board(board, 0);

        do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(123)));}} while(0);



        rc = read_board_file(solution, solution_names[i]);

        do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(126)));}} while(0);



        UnityAssertEqualIntArray(( const void*)((solution)), ( const void*)((board)), (UNITY_UINT32)((9*9)), (

       ((void *)0)

       ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT, UNITY_ARRAY_TO_ARRAY);

    }

}

void test_solve_invalid_board(void) {

    int board[9][9];

    char *board_names[3] =

        {"../testing_boards/invalid_s03a_1.txt",

         "../testing_boards/invalid_s03a_2.txt",

         "../testing_boards/invalid_s03a_3.txt"};

    int i, rc;



    for(i = 0; i < 3; i++) {

        rc = read_board_file(board, board_names[i]);

        do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(149)));}} while(0);



        rc = solve_board(board, 0);

        do {if ((rc == -1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(152)));}} while(0);

    }

}



void test_valid_unique_solution(void) {

    int board[9][9];

    int rc;



    rc = read_board_file(board, "../testing_boards/s03a.txt");

    do {if ((rc == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(161)));}} while(0);



    do {if ((unique_solution(board) == 0)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(163)));}} while(0);

}



void test_invalid_unique_solution(void) {

    int board[9][9] = {0};



    do {if ((unique_solution(board) == -1)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(169)));}} while(0);

}



void test_solvable_generate_board(void) {

    int board[9][9];

    int rc;



    generate_board(board);

    rc = solve_board(board, 0);

    do {if ((rc == 0)) {} else {UnityFail( ((("Could not solve generated board"))), (UNITY_UINT)((UNITY_UINT)(178)));}} while(0);

}













void test_unique_generate_board(void) {

    int board[9][9];

    int different_board[9][9];

    int i, x, y;



    generate_board(board);



    for(i = 0; i < 5; i++) {

        generate_board(different_board);

        for(y = 0; y < 9; y++) {

            for(x = 0; x < 9; x++) {

                if(board[x][y] != different_board[x][y]) {

                    longjmp(Unity.AbortFrame, 1);

                }

            }

        }

    }



    UnityFail( (("Generated boards are not different")), (UNITY_UINT)(204));

}





void test_generate_board_unique_solution(void) {

    int board[9][9];



    generate_board(board);

    do {if ((unique_solution(board) == 0)) {} else {UnityFail( ((("Generated board has multiple solutions"))), (UNITY_UINT)((UNITY_UINT)(212)));}} while(0)

                                                                 ;

}



void test_generate_board_has_empty_cells(void) {

    int board[9][9];

    int x, y;



    generate_board(board);

    for(y = 0; y < 9; y++) {

        for(x = 0; x < 9; x++) {

            if(board[x][y] == 0) {

                longjmp(Unity.AbortFrame, 1);

            }

        }

    }

    UnityFail( (("Generated board has no empty cells")), (UNITY_UINT)(228));

}
