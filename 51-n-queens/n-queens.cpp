class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n));
        vector<vector<string>> results;

        solve(0, n, board, results);

        return results;
    }

    void solve(int row, int n, vector<vector<bool>> &board, vector<vector<string>> &results) {
        if (row == n) {
            results.push_back(constructResult(board, n));
            return;
        }

        for (int col=0; col<n; col++) {
            if (canPlace(board, row, col, n)) {
                board[row][col] = true;
                solve(row+1, n, board, results);
                board[row][col] = false;
            }
        }
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

    vector<string> constructResult(vector<vector<bool>> &board, int n) {
        vector<string> result;

        for (int i=0; i<n; i++) {
            string row = "";
            for (int j=0; j<n; j++) {
                row += board[i][j] ? 'Q' : '.';
            }

            result.push_back(row);
        }

        return result;
    }
};