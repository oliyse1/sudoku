#ifndef SUDOKU_H
#define SUDOKU_H

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]);

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]);

//is_complete function which takes a 9x9 array of characters and returns true if the Sudoku board is fully occupied by digits
bool is_complete(const char board[9][9]);

//make_move function which attempts to place a digit onto a Sudoku board at a given position, returns false if move is invalid
bool make_move(const char* position, const char digit, char board[9][9]);

//save_board function outputs the 2D character array board to a file with name filename
bool save_board(const char* filename, const char board[9][9]);

//solve_board function attempts to solve the Sudoku puzzle
bool solve_board(char board[9][9]);

//helper function for solve_board, finds the next empty position				       	
bool find_next_empty_position(int &row, int &col, const char board[9][9]);


//function overloading, this version of solve_board function attempts to solve the Sudoku puzzle, while taking in another integer paramter which keeps track of the number of moves made
bool solve_board(char board[9][9], int &count);


#endif
