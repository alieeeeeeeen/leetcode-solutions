class Solution {
private:
    bool isSafe(vector<string> board, int row, int col, int n) {
        int r = row;
        int c = col;

        // only check the left side
        while(row >=0 && col >=0) { // upper left diagonal
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = r;
        col = c;
        while(col >=0) { // left
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = r;
        col = c;
        while( row < n && col >= 0) { // bottom left diagonal
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }


    void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(ans, board, n, col + 1);
                board[row][col] = '.'; // backtracking
            }
        }        
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n, '.');
        for (int i = 0; i < n; i++) board.push_back(s);

        solve(ans, board, n, 0);
        return ans;

    }
};