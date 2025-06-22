class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n));
        return solve(0, n, board);
    }

    int solve(int row, int n, vector<vector<bool>> &board) {
        if (row == n) {
            return 1;
        }

        int ways = 0;

        for (int col=0; col<n; col++) {
            if (canPlace(board, row, col, n)) {
                board[row][col] = true;
                ways += solve(row+1, n, board);
                board[row][col] = false;
            }
        }

        return ways;
    }

    bool canPlace(vector<vector<bool>> &board, int row, int col, int n) {
        for (const bool &status : board[row]) {
            if (status) return false;
        }

        for (int i=0; i<row; i++) {
            if (board[i][col]) return false;
        }

        int i=row-1, j=col-1;
        while (i>=0 && j>=0) {
            if (board[i][j]) return false;
            i--, j--;
        }

        i=row-1, j=col+1;
        while (i>=0 && j<n) {
            if (board[i][j]) return false;
            i--, j++;
        }

        return true;
    }
};