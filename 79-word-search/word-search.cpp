class Solution {
public:

    int n, m;

    bool issafe(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    bool find(int i, int j, vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int k) {
        if (k == word.size()) {
            return true;
        }

        if (!issafe(i, j) || visited[i][j] || board[i][j] != word[k]) {
            return false;
        }

        visited[i][j] = true;

        // Try all four directions
        if (find(i + 1, j, board, word, visited, k + 1) ||
            find(i - 1, j, board, word, visited, k + 1) ||
            find(i, j + 1, board, word, visited, k + 1) ||
            find(i, j - 1, board, word, visited, k + 1)) {
            return true;
        }

        visited[i][j] = false; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (find(i, j, board, word, visited, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
