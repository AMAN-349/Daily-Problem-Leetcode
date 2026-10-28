class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n,m;


    void find(int i, int j, int x, vector<vector<int>>& grid)
    {
        if (i >= n || j >= m)
            return;

        if (i == n - 1 && j == m - 1)
        {
            dp[i][j][grid[i][j]] = 1;
            return;
        }

        for (int k = 0; k < 1024; k++)
        {
            if (dp[i][j][k] == 1)
                return;
        }

        int curr = grid[i][j];

        find(i + 1, j, x, grid);
        find(i, j + 1, x, grid);

        if (i + 1 < n)
        {
            for (int k = 0; k < 1024; k++)
            {
                if (dp[i + 1][j][k] == 1)
                    dp[i][j][curr ^ k] = 1;
            }
        }

        if (j + 1 < m)
        {
            for (int k = 0; k < 1024; k++)
            {
                if (dp[i][j + 1][k] == 1)
                    dp[i][j][curr ^ k] = 1;
            }
        }
    }

    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        dp.resize(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        find(0,0,0,grid);
        int ans=INT_MAX;

        for (int k = 0; k < 1024; k++)
        {
            if (dp[0][0][k] == 1)
                return k;
        }
        return -1;
    }
};