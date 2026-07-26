class Solution {
public:

    // Function to check if placing character c at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        // Check all rows in current column
        for (int i = 0; i < 9; i++) {
            // If character already exists in column, not valid
            if (board[i][col] == c)
                return false;
        }

        // Check all columns in current row
        for (int j = 0; j < 9; j++) {
            // If character already exists in row, not valid
            if (board[row][j] == c)
                return false;
        }

        // Calculate start indices of the 3x3 sub-box
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);

        // Check the 3x3 sub-box for duplicate character
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // If character found in sub-box, not valid
                if (board[boxRowStart + i][boxColStart + j] == c)
                    return false;
            }
        }

        // If all checks passed, placement is valid
        return true;
    }

    // Recursive function to solve Sudoku using backtracking
    bool solveSudoku(vector<vector<char>> &board) {
        // Traverse each cell in the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // If current cell is empty
                if (board[i][j] == '.') {
                    // Try all possible digits
                    for (char c = '1'; c <= '9'; c++) {
                        // Check if placing c is valid here
                        if (isValid(board, i, j, c)) {
                            // Place c tentatively
                            board[i][j] = c;

                            // Recur to solve rest of the board
                            if (solveSudoku(board))
                                return true; // If successful, return true

                            // If not successful, backtrack
                            board[i][j] = '.';
                        }
                    }
                    // If no digit can be placed here, return false to backtrack
                    return false;
                }
            }
        }
        // If all cells are filled correctly, return true
        return true;
    }
};
