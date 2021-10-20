void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool make_move(const char position[3], const char digit, char board[9][9]);
bool save_board(const char* filename, const char board[9][9]);
bool solve_board(char board[9][9]);
void find_next_empty_position(int &row, int &col, const char board[9][9]);
