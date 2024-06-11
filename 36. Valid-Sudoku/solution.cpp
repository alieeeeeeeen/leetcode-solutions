class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(hasDuplicate(board, i, 9, 0, 0)) { // check each row
                return false;
            }
        }

        for (int j = 0; j < 9; j++) {
            if(hasDuplicate(board, 0, 9, j, 0)) { // check each column
                return false;
            }
        }

        for (int i = 0; i < 9; i+=3) { // check each region
            for(int j = 0; j < 9; j+=3) {
                if(hasDuplicate(board, i, i+3, j, j+3)) {
                    return false;
                }
            }
        }
        return true;

    }
    private:
        bool hasDuplicate(vector<vector<char>>& board, int row_start, int row_end, int column_start,
        int column_end) {
            vector<bool> is_present(9, false);
            for(int i = row_start; i < row_end; ++i) { // check from row_start to row_end
                for (int j = column_start; j < column_end; ++j) { // check from column_start to column_end
                    if(board[i][j] != '.') { // if it is not equal to '.', since '.' is excluded
                        if(is_present[board[i][j]]) {
                            return true;
                        }
                        is_present[board[i][j]] = true; // if not present before, set the flag as true to indicate it presents now
                    }
                }
            }
            return false;
        }
};