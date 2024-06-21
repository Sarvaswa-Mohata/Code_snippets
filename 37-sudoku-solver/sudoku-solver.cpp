class Solution {
public:
    // Check if it's valid to place 'num' at board[i][j]
    bool check(int i, int j, char num, vector<vector<char>>& board) {
        for (int ind = 0; ind < 9; ind++) {
            // Check the row and column
            if (board[ind][j] == num || board[i][ind] == num) {
                return false;
            }
        }

        // Correctly calculate the starting indices of the 3x3 box
        int boxRowStart = (i / 3) * 3;  // CHANGED: Corrected box row calculation
        int boxColStart = (j / 3) * 3;  // CHANGED: Corrected box column calculation
        for (int row = boxRowStart; row < boxRowStart + 3; row++) {
            for (int col = boxColStart; col < boxColStart + 3; col++) {
                if (board[row][col] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    // Recursive function to solve the Sudoku board
    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // Try placing numbers '1' to '9'
                    for (char num = '1'; num <= '9'; num++) {  // CHANGED: Using char '1' to '9'
                        if (check(i, j, num, board)) {
                            board[i][j] = num;
                            if (helper(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';  // Backtrack if not solvable
                            }
                        }
                    }
                    return false; // If no number can be placed, backtrack
                }
            }
        }
        return true; // If the entire board is filled correctly
    }

    // Entry function to initiate the solving process
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};
