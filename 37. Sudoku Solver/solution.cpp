class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
private:
    bool solver(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) { // loop for each row
            for (int j = 0; j < 9; ++j) { // loop for each column
               if(board[i][j] == '.') { // if the space is needed to be filled
                 for (int k = 1; k <= 9; ++k) { // choose number from 1 to 9
                    board[i][j] = k + '0'; // convert int to char
                    if(isValid(board, i, j) && solver(board)) { // if the number filled in is valid
                        return true; // return true;
                    }
                    board[i][j] = '.'; // else set the space to the default value
                 }
                 return false;
               }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int x, int y) {
        // valid for each row
        for (int i = 0; i <9; ++i) {
            if (i != x && board[i][y] == board[x][y]) {
                return false;
            }
        }

        // valide for each column
        for (int j = 0; j < 9; ++j) {
            if(j != y && board[x][j] == board[x][y]) {
                return false;
            }
        }

        // valide for each grid
        for(int i =  3 * (x / 3); i < 3 * (x / 3 + 1); ++i) {
            for(int j = 3 * (y / 3); j < 3 * (y / 3 + 1); ++j) {
                if((i != x && j != y) && board[i][j] == board[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }
};