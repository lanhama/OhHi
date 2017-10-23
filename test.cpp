/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
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
void testing_board_has_no_duplicates();


int main() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    testing_board_has_no_duplicates();

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

void testing_board_has_no_duplicates() {
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
