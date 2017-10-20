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

// declare more test functions here

int main() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();


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
    
    cout << endl;
}
