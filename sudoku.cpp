#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in) {
    cout << "Failed!\n";
  }
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3)) {
    cout << "  +===========+===========+===========+\n";
  } else {
    cout << "  +---+---+---+---+---+---+---+---+---+\n";
  }
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|\n";
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) {
    cout << (char) ('1'+r) << "   ";
  }
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */

//is_complete function which takes a 9x9 array of characters and check if the Sudoku board is fully occupied by digits

bool is_complete(const char board[9][9]) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (!isdigit(board[row][col])) {
					return false;
			}
		}
	}
	return true;
}



//make_move function which attempts to place a digit onto a Sudoku board at a given position

bool make_move(const char position[3], const char digit, char board[9][9]) {
	
	int position_row = position[0] - 'A';
	int position_col = position[1] - '1';
	
	if (position[0] < 'A' || position[0] >'I' || position[1] < '1' || position[1] > '9') {
		return false;
	}
	
	for (int row = 0; row < 9; row++) {
		if (board[row][position_col] == digit) {
			return false;
		}
	}
	for (int col = 0; col < 9; col++) {
		if (board[position_row][col] == digit) {
			return false;
		}
	}
	int section_row = position_row / 3;
	int section_col = position_col / 3;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (board[section_row * 3 + row][section_col * 3 + col] == digit) {
				return false;
			}
		}
	}	
	board[position_row][position_col] = digit;
	return true;
}

//save_board function outputs the 2D array board to a file with filename.

bool save_board(const char* filename, const char board[9][9]) {
	ofstream out_stream;
	out_stream.open(filename);
	for (int row = 0; row < 9; row++){
		for(int col = 0; col < 9; col++) {
			out_stream << board[row][col];
		}
		out_stream << endl;
	}
	out_stream.close();
	return true;
}


//solve_board function attempts to solve the Sudoku puzzle

bool solve_board(char board[9][9]) {
	int row = 0;
	int col = 0;
	find_next_empty_position(row, col, board);

	char position[2];
	position[0] = 'A' + row;
	position[1] = '1' + col;
	for (char digit = '1'; digit <= '9'; digit++) {
		if (make_move(position, digit, board)) {
			if (is_complete(board)) {
				return true;
			} else {
				if (solve_board(board)) {
					return true;
			        } else {
					continue;
				}
			} 
		} else {
			continue;
		}	
	}
	board[row][col] = '.';
	return false;
}
				       	
void find_next_empty_position(int &row, int &col, const char board[9][9]) {
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if ((board[row][col] < '1') || (board[row][col] > '9')) {
				return;
			} else {
				continue;
			}
		}
	}
}




