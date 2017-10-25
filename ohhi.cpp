/**
 * ohhi.cpp
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2017
 *
 * Adam Schreck, Andrew Lanham
 * schrecka, lanhama
 *
 * In this project, you will develop a command-line application to read, check,
 *      solve, and play basic instances of 0h h1, a Sudoku-like puzzle game.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int i = 0;
    int k = 0;
    int numUnknown = 0;
    
    for (i = 0; i < size; ++i) {
        for (k = 0; k < size; ++k) {
            if (board[i][k] == UNKNOWN) {
                numUnknown += 1;
            }
        }
    }
    return numUnknown;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    int i = 0;
    
    for (i = 0; i < (size - 2); i++) {
        if (board[row][i] == color) {
            if (board[row][i + 1] == color) {
                if (board[row][i + 2] == color) {
                    return false;
                }
            }
        }
    }
    return true;
}


bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    int i;
    for (i = 0; i < (size - 2); i++) {
        if (board[i][col] == color) {
            if (board[i + 1][col] == color) {
                if (board[i + 2][col] == color) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int row;
    int column;
    int color;
    
    for (color = RED; color <= BLUE; color++) {
        for (row = 0; row < size; row++) {
            if (!(row_has_no_threes_of_color(board, size, row, color))) {
                return false;
            }
        }
        for (column = 0; column < size; column++) {
            if (!(col_has_no_threes_of_color(board, size, column, color))) {
                return false;
            }
        }
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (board[row1][i] == UNKNOWN || board[row2][i] == UNKNOWN) {
            return true;
        }
        if (board[row1][i] != board[row2][i]) {
            return true;
        }
    }
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (board[i][col1] == UNKNOWN || board[i][col2] == UNKNOWN) {
            return true;
        }
        if (board[i][col1] != board[i][col2]) {
            return true;
        }
    }
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int i;
    int k;
    for (i = 0; i < (size - 1); i++) {
        for (k = (i + 1); k <= (size - 1); k++) {
            if (!(rows_are_different(board, size, i, (k)))) {
                return false;
            }
        }
    }
    for (i = 0; i < (size - 1); i++) {
        for (k = (i + 1); k <= (size - 1); k++) {
            if (!(cols_are_different(board, size, i, (k)))) {
                return false;
            }
        }
    }
    return true;
}

///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    int i;
    
    
    for (i = 0; i < (size - 2); i++) {
        // checks for two of same color after i
        if (board[row][i + 1] == board[row][i + 2] && board[row][i] == UNKNOWN){
            if (board[row][i + 1] == BLUE) {
                mark_square_as(board, size, row, i, RED, announce);
            }
            else if (board[row][i + 1] == RED) {
                mark_square_as(board, size, row, i, BLUE, announce);
            }
        }
        //checks for two of same color for i and i+1
        else if (board[row][i] == board[row][i + 1]
                     && board[row][i + 2] == UNKNOWN){
            if (board[row][i] == BLUE) {
                mark_square_as(board, size, row, i + 2, RED, announce);
            }
            if (board[row][i] == RED) {
                mark_square_as(board, size, row, i + 2, BLUE, announce);
            }
        }
        //checks for color sandwich
        else if (board[row][i + 1] == UNKNOWN) {
            if (board[row][i] == board[row][i + 2]) {
                if (board[row][i] == BLUE) {
                    mark_square_as(board, size, row, i + 1, RED, announce);
                }
                else if (board[row][i] == RED) {
                    mark_square_as(board, size, row, i + 1, BLUE, announce);
                }
            }
        }
        
    }
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    int i;
    
    for (i = 0; i < (size - 2); i++) {
        if (board[i + 1][col] == board[i + 2][col] && board[i][col] == UNKNOWN) {
            if (board[i + 1][col] == BLUE) {
                mark_square_as(board, size, i, col, RED, announce);
            }
            else if (board[i + 1][col] == RED) {
                mark_square_as(board, size, i, col, BLUE, announce);
            }
        }
        //checks for two consecutive in a column
        else if (board[i][col] == board[i + 1][col] && board[i + 2][col] == UNKNOWN){
            if (board[i][col] == BLUE) {
                mark_square_as(board, size, (i + 2), col, RED, announce);
            }
            if (board[i][col] == RED) {
                mark_square_as(board, size, (i + 2), col, BLUE, announce);
            }
        }
        //checks for color sandwich
        else if (board[i + 1][col] == UNKNOWN) {
            if (board[i][col] == board[i + 2][col]) {
                if (board[i][col] == BLUE) {
                    mark_square_as(board, size, (i + 1), col, RED, announce);
                }
                else if (board[i][col] == RED) {
                    mark_square_as(board, size, (i + 1), col, BLUE, announce);
                }
            }
        }
    }
}
void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int i;
    int k;
    int n;
    
    int redCount = 0;
    int blueCount = 0;
    for (i = 0; i < size; i++) {
        if (board[row][i] == RED) {
            redCount++;
        }
        if (board[row][i] == BLUE) {
            blueCount++;
        }
    }
    if (redCount == (size / 2)) {
        for (k = 0; k < size;k++) {
            if (board[row][k] == UNKNOWN) {
                mark_square_as(board, size, row, k, BLUE, announce);
            }
        }
    }
    if (blueCount == (size / 2)) {
        for (n = 0; n < size; n++) {
            if (board[row][n] == UNKNOWN) {
                mark_square_as(board, size, row, n, RED, announce);
            }
        }
    }
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int i;
    int k;
    int n;
    int redCount = 0;
    int blueCount = 0;
    
    for (i = 0; i < size; i++) {
        if (board[i][col] == RED) {
            redCount++;
        }
        else if (board[i][col] == BLUE) {
            blueCount++;
        }
    }
    if (redCount == (size / 2)) {
        for (k = 0; k < size; k++) {
            if (board[k][col] == UNKNOWN) {
                mark_square_as(board, size, k, col, BLUE, announce);
            }
        }
    }
    if (blueCount == (size / 2)) {
        for (n = 0; n < size; n++) {
            if (board[n][col] == UNKNOWN) {
                mark_square_as(board, size, n, col, RED, announce);
            }
        }
    }
}

///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    //makes sure no unknown squares
    if (count_unknown_squares(board, size) == 0) {
        // makes sure rules are followed
        if (board_is_valid(board, size)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    
    }
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    char colLetter = 'A';
    int k = 0;
    
    // toupper function converts the char to an upper case letter.
    if (((row_input >= 1) && (row_input <= size))
            && ((toupper(col_input) >= 'A')
            && (toupper(col_input) <= ('A' + size - 1)))) {
        if (toupper(color_char) == 'X' || toupper(color_char) == 'O'
                || toupper(color_char) == '-') {
            row = row_input - 1;
            for (colLetter = 'A'; colLetter < toupper(col_input); colLetter++) {
                k++;
            }
                col = k;
                return true;
            }
        }
    cout << "Sorry, that's not a valid input." << endl;
    return false;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    int copy_board[MAX_SIZE][MAX_SIZE];
    int i, k;
    for (i = 0; i < size; i ++) {
        for  (k = 0; k < size; k++) {
            copy_board[i][k] = current_board[i][k];
        }
    }
    if (current_board[row][col] == original_board[row][col]
        && current_board[row][col] != UNKNOWN) {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    copy_board[row][col] = color;
    if (board_is_valid(copy_board, size)) {
        return true;
    }
    else {
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }
}



///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
