class Solution {
private:
int queen[9];


// In order to get the number of solutions, it would be better to store the coordinates instead of the whole board
bool isSafe(int &row, int &col, int n) {
    for (int i =0; i < row; i++) {
        int prev_row = i;
        int prev_col = queen[i];
        // check if the difference between rows and columns is the same, then these two will be on the diagonal
        if (prev_col == col || abs(row - prev_row ) == abs(col - prev_col)) return false;
    }
    return true;
}
int sovleNQueen(int row, int N) {
    if (row == N)
        return 1;
    
    int ans = 0;

    for (int col = 0; col < N; col++) { // loop for the col
        if(isSafe(row, col, N)) {
            queen[row] = col;
            ans += sovleNQueen(row + 1, N); // recursive in the row
            queen[row] = -1; // backtrack
        }
    }
    return ans;
}
public:
    int totalNQueens(int n) {
        memset(queen, -1, sizeof(queen));
        return sovleNQueen(0, n);
    }
};