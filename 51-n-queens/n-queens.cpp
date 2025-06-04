class Solution {
public:

    bool issafe(int i,int j,int n,vector<string>& board)
    {
        for(int k=0;k<i;k++)
        {
            if(board[k][j]=='Q')
                return false;
        }

        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--) {
            if (board[x][y] == 'Q')
                return false;
        }

        for (int x = i - 1, y = j + 1; x >= 0 && y < n; x--, y++) {
            if (board[x][y] == 'Q')
                return false;
        }

        return true;
    }

    void find(int row, vector<string>& board, int n, vector<vector<string>>& res)
    {
        if(row == n)
        {
            res.push_back(board);
            return;
        }

        for(int col=0; col<n; col++)
        {
            if(issafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                find(row + 1, board, n, res);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));  
        vector<vector<string>> res;
        find(0, board, n, res);
        return res;
    }
};
