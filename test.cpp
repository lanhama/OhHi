/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * Names: Adam Schreck, Andrew Lanham
 * Uniqnames: schrecka, lanhama
 *
 * In this project, you will develop a command-line application to read, check,
 *      solve, and play basic instances of 0h h1, a Sudoku-like puzzle game.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

int main() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_move();
    test_check_valid_input();

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing count_unknown_squares()" << endl;
   
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << " = 9" << endl;

    // test case 2
    string test_board_2[] = {"O-OX--",
                             "OO----",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_2 = 6;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << " = 21" << endl;
    
    // test case 3
    string test_board_3[] = {"O-OX--O-",
                             "OO----X-",
                             "X------O",
                             "-O----XX",
                             "OXO-O-OO",
                             "OXO-O---",
                             "OXO-O-OO",
                             "OXO-O-OO"};
    
    int size_3 = 8;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << " = 30" << endl;
    
    // test case 4
    string test_board_4[] = {"-X",
                             "OO"};
    int size_4 = 2;
    read_board_from_string(board, test_board_4, size_4);
    cout << count_unknown_squares(board, size_4) << " = 1" << endl;
    
    cout << endl;
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing row_has_no_threes_of_color()" << endl;
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    int row_1 = 0;
    int color_1 = BLUE;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 1 (true): "
         << row_has_no_threes_of_color(board, size_1, row_1, color_1) << endl;
    
    
    // test case 2
    string test_board_2[] = {"OOO-",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_2 = 4;
    int row_2 = 0;
    int color_2 = BLUE;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 0 (false): "
         << row_has_no_threes_of_color(board, size_2, row_2, color_2) << endl;
    
    // test case 3
    string test_board_3[] = {"OOO-",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_3 = 4;
    int row_3 = 1;
    int color_3 = BLUE;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 1 (true): "
    << row_has_no_threes_of_color(board, size_3, row_3, color_3) << endl;
    
    // test case 4
    string test_board_4[] = {"OOO-",
                             "OO--",
                             "-XXX",
                             "-O--"};
    int size_4 = 4;
    int row_4 = 2;
    int color_4 = RED;
    read_board_from_string(board, test_board_4, size_4);
    cout << "should = 0 (false): "
         << row_has_no_threes_of_color(board, size_4, row_4, color_4) << endl;
    
    // test case 5
    string test_board_5[] = {"OOO-",
                             "OO--",
                             "-XXX",
                             "-O--"};
    int size_5 = 4;
    int row_5 = 0;
    int color_5 = RED;
    read_board_from_string(board, test_board_5, size_5);
    cout << "should = 1 (true): "
         << row_has_no_threes_of_color(board, size_5, row_5, color_5) << endl;
    
    // test case 6
    string test_board_6[] = {"O-XX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_6 = 4;
    int row_6 = 0;
    int color_6 = RED;
    read_board_from_string(board, test_board_6, size_6);
    cout << "should = 1 (true): "
    << row_has_no_threes_of_color(board, size_6, row_6, color_6) << endl;
    
    cout << endl;
}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing col_has_no_threes_of_color()" << endl;
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    int col_1 = 0;
    int color_1 = BLUE;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 1 (true): "
    << col_has_no_threes_of_color(board, size_1, col_1, color_1) << endl;
    
    // test case 2
    string test_board_2[] = {"O-OX",
                             "OO--",
                             "O---",
                             "-O--"};
    int size_2 = 4;
    int col_2 = 0;
    int color_2 = BLUE;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 0 (false): "
    << col_has_no_threes_of_color(board, size_2, col_2, color_2) << endl;
    
    //test case 3
    string test_board_3[] = {"O-OX--",
                             "OO----",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_3 = 6;
    int col_3 = 0;
    int color_3 = BLUE;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 1 (true): "
    << col_has_no_threes_of_color(board, size_3, col_3, color_3) << endl;
    
    //test case 4
    string test_board_4[] = {"O-OX--",
                             "OO----",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_4 = 6;
    int col_4 = 1;
    int color_4 = BLUE;
    read_board_from_string(board, test_board_4, size_4);
    cout << "should = 1 (true): "
    << col_has_no_threes_of_color(board, size_4, col_4, color_4) << endl;
    
    // test case 5
    string test_board_5[] = {"O-OX",
                             "OO--",
                             "O---",
                             "-O--"};
    int size_5 = 4;
    int col_5 = 0;
    int color_5 = RED;
    read_board_from_string(board, test_board_5, size_5);
    cout << "should = 1 (true): "
    << col_has_no_threes_of_color(board, size_5, col_5, color_5) << endl;
    
    //test case 6
    string test_board_6[] = {"O-OX--",
                             "OO----",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_6 = 6;
    int col_6 = 1;
    int color_6 = RED;
    read_board_from_string(board, test_board_6, size_6);
    cout << "should = 1 (true): "
    << col_has_no_threes_of_color(board, size_6, col_6, color_6) << endl;
    
    cout << endl;
}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing board_has_no_threes()" << endl;
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 1 (true): "
    << board_has_no_threes(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"O-OX",
                             "OO--",
                             "XO--",
                             "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 0 (false): "
    << board_has_no_threes(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"O-OX",
                             "OO--",
                             "XO--",
                             "-XXX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 0 (false): "
    << board_has_no_threes(board, size_3) << endl;
    
    //test case 4
    string test_board_4[] = {"O-OX--",
                             "OO----",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    cout << "should = 1 (true): "
    << board_has_no_threes(board, size_4) << endl;
    
    cout << endl;
}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing rows_are_different()" << endl;
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OOXX",
                             "OOXX",
                             "-XXX"};
    int size_1 = 4;
    int row1_1 = 0;
    int row2_1 = 1;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 1 (true): "
    << rows_are_different(board, size_1, row1_1, row2_1) << endl;
    
    // test case 2
    string test_board_2[] = {"O-OX",
                             "OOXX",
                             "OOXX",
                             "-XXX"};
    int size_2 = 4;
    int row1_2 = 1;
    int row2_2 = 2;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 0 (false): "
    << rows_are_different(board, size_2, row1_2, row2_2) << endl;
    
    // test case 3
    string test_board_3[] = {"O-OX",
                             "OO--",
                             "OO--",
                             "-XXX"};
    int size_3 = 4;
    int row1_3 = 1;
    int row2_3 = 2;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 1 (true): "
    << rows_are_different(board, size_3, row1_3, row2_3) << endl;
    
    cout << endl;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing cols_are_different()" << endl;
    
    // test case 1
    string test_board_1[] = {"XXOO",
                             "OOXX",
                             "OOXX",
                             "XXOO"};
    int size_1 = 4;
    int row1_1 = 0;
    int row2_1 = 1;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 0 (false): "
    << cols_are_different(board, size_1, row1_1, row2_1) << endl;
    
    // test case 2
    string test_board_2[] = {"XXOO",
                             "OOXX",
                             "OOXX",
                             "XXOO"};
    int size_2 = 4;
    int row1_2 = 1;
    int row2_2 = 2;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 1 (true): "
    << cols_are_different(board, size_2, row1_2, row2_2) << endl;
    
    // test case 3
    string test_board_3[] = {"XXOO",
                             "O-XX",
                             "OOXX",
                             "XXOO"};
    int size_3 = 4;
    int row1_3 = 1;
    int row2_3 = 2;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 1 (true): "
    << cols_are_different(board, size_3, row1_3, row2_3) << endl;
    
    cout << endl;
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing board_has_no_duplicates()" << endl;
    
    // test case 1
    string test_board_1[] = {"OO--",
                             "XXOO",
                             "XXO-",
                             "O-X-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 1 (true): "
    << board_has_no_duplicates(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"OO--",
                             "XXOO",
                             "XXOO",
                             "O-O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 0 (false): "
    << board_has_no_duplicates(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"OO--",
                             "O-O-",
                             "XXOO",
                             "XXOO"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 0 (false): "
    << board_has_no_duplicates(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"OOOO",
                             "O-O-",
                             "X-OO",
                             "XXOO"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "should = 1 (true): "
    << board_has_no_duplicates(board, size_4) << endl;
    
    // test case 5
    string test_board_5[] = {"OOOO",
                             "O-OO",
                             "X-OO",
                             "XXOO"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "should = 0 (false): "
    << board_has_no_duplicates(board, size_5) << endl;
    
    cout << endl;
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];
    int announce = true;
    
    cout << "testing solve_three_in_a_row()" << endl;
    
    // test case 1
    cout << endl << "test 1" << endl;
    string test_board_1[] = {"OO--",
                             "XXOO",
                             "XXO-",
                             "O-X-"};
    
    int size_1 = 4;
    int row_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    solve_three_in_a_row(board, size_1, row_1, announce);
    print_board(board, size_1);
    
    // test case 2
    cout << endl << "test 2" << endl;
    string test_board_2[] = {"OO--",
                             "XXOO",
                             "XXO-",
                             "O-X-"};
    
    int size_2 = 4;
    int row_2 = 2;
    read_board_from_string(board, test_board_2, size_2);
    cout << "no change: ";
    solve_three_in_a_row(board, size_2, row_2, announce);
    cout << endl;
    
    //test case 3
    cout << endl << "test 3" << endl;
    string test_board_3[] = {"O-OX--",
                             "-XX---",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_3 = 6;
    int row_3 = 1;
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    solve_three_in_a_row(board, size_3, row_3, announce);
    print_board(board, size_3);
    cout << endl;
    
    // test case 4
    cout << endl << "test 4" << endl;
    string test_board_4[] = {"O-OX--",
                             "-XX---",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_4 = 6;
    int row_4 = 0;
    read_board_from_string(board, test_board_4, size_4);
    print_board(board, size_4);
    solve_three_in_a_row(board, size_4, row_4, announce);
    print_board(board, size_4);
    cout << endl;
    
    // test case 5
    cout << endl << "test 5" << endl;
    string test_board_5[] = {"O-OXX-",
                             "-XX---",
                             "X-----",
                             "-O----",
                             "OXO-O-",
                             "OXO-O-"};
    int size_5 = 6;
    int row_5 = 0;
    read_board_from_string(board, test_board_5, size_5);
    print_board(board, size_5);
    solve_three_in_a_row(board, size_5, row_5, announce);
    print_board(board, size_5);
    cout << endl;
}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];
    int announce = true;
    cout << "testing solve_three_in_a_column()" << endl;
    
    //test case 1
    string test_board_1[] = {
        "O-OX--",
        "OXX---",
        "------",
        "-O----",
        "OXO-O-",
        "OXO-O-"};
    int size_1 = 6;
    int col_1 = 0;
    
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    cout << endl;
    solve_three_in_a_column(board, size_1, col_1, announce);
    print_board(board, size_1);
    cout << endl;
    
    // test case 2
    string test_board_2[] = {
        "O-OXX-",
        "OXX-X-",
        "------",
        "-O----",
        "OXO-O-",
        "OXO-O-"};
    
    int size_2 = 6;
    int col_2 = 4;
    
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    cout << endl;
    solve_three_in_a_column(board, size_2, col_2, announce);
    print_board(board, size_2);
    cout << endl;
    
    // test case 3
    string test_board_3[] = {
        "O-OXX-",
        "OXX-X-",
        "------",
        "-O----",
        "OXO-O-",
        "OXO-O-"};
    
    int size_3 = 6;
    int col_3 = 4;
    
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    cout << endl;
    solve_three_in_a_column(board, size_3, col_3, announce);
    print_board(board, size_3);
    cout << endl;
}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];
    int announce = true;
    
    cout << "testing solve_balance_row" << endl;
    // test case 1
    string test_board_1[] =
    {"X-X-",
        "XXOO",
        "----",
        "XXOX"};
    
    int size_1 = 4;
    int row_1 = 0;
    
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    cout << endl;
    solve_balance_row(board, size_1, row_1, announce);
    print_board(board, size_1);
    cout << endl;
    
    // test case 2
    string test_board_2[] =
    {"X-X-",
        "XXOO",
        "----",
        "XXOX"};
    
    int size_2 = 4;
    int row_2 = 3;
    
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    cout << "no change" << endl;
    solve_balance_row(board, size_2, row_2, announce);
    print_board(board, size_2);
    cout << endl;
    
    //test case 3
    string test_board_3[] =
    {"X-X-",
        "XXOO",
        "--OO",
        "XXOX"};
    
    int size_3 = 4;
    int row_3 = 2;
    
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    cout << endl;
    solve_balance_row(board, size_3, row_3, announce);
    print_board(board, size_3);
    cout << endl;
    
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];
    int announce = true;
    
    cout << "testing solve_balance_column" << endl << endl;
    // test case 1
    string test_board_1[] =
    {"X---",
        "XOO-",
        "-XOX",
        "-XX-"};
    
    int size_1 = 4;
    int col_1 = 0;
    
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    cout << endl;
    solve_balance_column(board, size_1, col_1, announce);
    print_board(board, size_1);
    cout << endl;
    // test case 2
    string test_board_2[] =
    {"XO--",
        "XOO-",
        "OXOX",
        "OXX-"};
    
    int size_2 = 4;
    int col_2 = 1;
    
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    cout << endl;
    solve_balance_column(board, size_2, col_2, announce);
    print_board(board, size_2);
    cout << endl;
}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];
    
    cout << "testing board_is_solved" << endl << endl;
    
    // test case 1
    string test_board_1[] =
        {"X---",
        "XOO-",
        "-XOX",
        "-XX-"};
    
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "should = 0 (false): "
    << board_is_solved(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] =
       {"XXOO",
        "OOXX",
        "XOXO",
        "OXOX"};
    
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "should = 1 (true): "
    << board_is_solved(board, size_2) << endl;
    
    cout << endl;
    
    // test case 3
    string test_board_3[] =
       {"OOXO",
        "OXXO",
        "XOOX",
        "XXOO"};
    
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "should = 0 (false): "
    << board_is_solved(board, size_2) << endl;
    
    cout << endl;
}


void test_check_valid_move() {
    int original_board[MAX_SIZE][MAX_SIZE];
    int current_board[MAX_SIZE][MAX_SIZE];
    cout << "testing check_valid_move" << endl << endl;
    
    string test_original_board_1[] =
       {"----",
        "XXO-",
        "-XO-",
        "--X-"};
    
    string test_current_board_1[] =
       {"---X",
        "XXOO",
        "XXO-",
        "--X-"};
    
    int size = 4;
    read_board_from_string(original_board, test_original_board_1, size);
    print_board(original_board, size);
    read_board_from_string(current_board, test_current_board_1, size);
    print_board(current_board, size);
    // test case 1
    int row_1 = 3;
    int col_1 = 2;
    int color_1 = BLUE;
    
    cout << "original squares error: " << endl <<
    check_valid_move(original_board, current_board, size, row_1, col_1, color_1)
    << endl;
    
    //test case 2
    int row_2 = 2;
    int col_2 = 3;
    int color_2 = BLUE;
    
    cout << "move breaks rule: " << endl <<
    check_valid_move(original_board, current_board, size, row_2, col_2, color_2)
    << endl;
    
    //test case 3
    int row_3 = 0;
    int col_3 = 0;
    int color_3 = BLUE;
    
    cout << "should = 1 (true): " << 
    check_valid_move(original_board, current_board, size, row_3, col_3, color_3)
    << endl;
    
    //test case 4
    int row_4 = 1;
    int col_4 = 3;
    int color_4 = UNKNOWN;
    
    cout << "should = 1 (true): " <<
    check_valid_move(original_board, current_board, size, row_4, col_4, color_4)
    << endl;
    
    //test case 5
    int row_5 = 0;
    int col_5 = 3;
    int color_5 = BLUE;
    
    cout << "should = 1 (true): " <<
    check_valid_move(original_board, current_board, size, row_5, col_5, color_5)
    << endl;
    cout << endl;
}

void test_check_valid_input() {
    // test case 1
    int size_1 = 4;
    int rowInput = 2;
    char colInput = 'A';
    char colorChar = 'X';
    int row = -1;
    int col = -1;
    check_valid_input(size_1, rowInput, colInput, colorChar, row, col);
    cout << "number of rows: " << row << endl;
    cout << "number of columns: " << col << endl;
    //test case 2
    int size_2 = 4;
    int rowInput_2 = 0;
    char colInput_2 = 'A';
    char colorChar_2 = 'X';
    int row_2 = -1;
    int col_2 = -1;
    check_valid_input(size_2, rowInput_2, colInput_2, colorChar_2, row_2, col_2);
    cout << "number of rows: " << row_2 << endl;
    cout << "number of columns: " << col_2 << endl;
    // test case 3
    int size_3 = 4;
    int rowInput_3 = 2;
    char colInput_3 = 'f';
    char colorChar_3 = 'X';
    int row_3 = -1;
    int col_3 = -1;
    cout << "should return invalid input: " << endl;
    check_valid_input(size_3, rowInput_3, colInput_3, colorChar_3, row_3, col_3);
    cout << "number of rows: " << row_3 << endl;
    cout << "number of columns: " << col_3 << endl;
    //test case 4
    int size_4 = 4;
    int rowInput_4 = 2;
    char colInput_4 = 'f';
    char colorChar_4 = 'Y';
    int row_4 = -1;
    int col_4 = -1;
    cout << "should return invalid input: " << endl;
    check_valid_input(size_4, rowInput_4, colInput_4, colorChar_4, row_4, col_4);
    cout << "number of rows: " << row_4 << endl;
    cout << "number of columns: " << col_4 << endl << endl;
    // test case 5
    int size_5 = 4;
    int rowInput_5 = 4;
    char colInput_5 = 'c';
    char colorChar_5 = 'X';
    int row_5 = -1;
    int col_5 = -1;
    check_valid_input(size_5, rowInput_5, colInput_5, colorChar_5, row_5, col_5);
    cout << "number of rows: " << row_5 << endl;
    cout << "number of columns: " << col_5 << endl;
}

