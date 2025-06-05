class Solution {
public:

    // Helper to get 3x3 matrix index from cell position
    int getMatNum(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }

    // Recursive backtracking solver
    void solve(vector<vector<char>>& board, int i, int j, bool& solved,
               vector<vector<int>>& rowFreq, vector<vector<int>>& colFreq,
               vector<vector<int>>& matFreq) {

        if (solved) return;

        // If reached end of board
        if (i == 9) {
            solved = true;
            return;
        }

        // Move to next cell
        int ni = (j == 8) ? i + 1 : i;
        int nj = (j == 8) ? 0 : j + 1;

        if (board[i][j] != '.') {
            solve(board, ni, nj, solved, rowFreq, colFreq, matFreq);
            return;
        }

        int boxIdx = getMatNum(i, j);
        for (int num = 1; num <= 9; ++num) {
            int idx = num - 1;
            if (rowFreq[i][idx] == 0 && colFreq[j][idx] == 0 && matFreq[boxIdx][idx] == 0) {
                // Place number
                board[i][j] = num + '0';
                rowFreq[i][idx]++;
                colFreq[j][idx]++;
                matFreq[boxIdx][idx]++;

                solve(board, ni, nj, solved, rowFreq, colFreq, matFreq);
                if (solved) return;

                // Backtrack
                board[i][j] = '.';
                rowFreq[i][idx]--;
                colFreq[j][idx]--;
                matFreq[boxIdx][idx]--;
            }
        }
    }

    // Driver
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowFreq(9, vector<int>(9, 0));
        vector<vector<int>> colFreq(9, vector<int>(9, 0));
        vector<vector<int>> matFreq(9, vector<int>(9, 0));

        // Initialize frequencies
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0' - 1;
                    rowFreq[i][val]++;
                    colFreq[j][val]++;
                    matFreq[getMatNum(i, j)][val]++;
                }
            }
        }

        bool solved = false;
        solve(board, 0, 0, solved, rowFreq, colFreq, matFreq);
    }
};
