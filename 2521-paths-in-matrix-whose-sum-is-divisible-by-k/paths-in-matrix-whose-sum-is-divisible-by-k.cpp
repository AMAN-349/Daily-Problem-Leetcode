class Solution {
public:
    int modVal = 1e9 + 7;

    int find(int i, int j, int desti, int destj,
             vector<vector<int>>& grid, int rem, int k,
             vector<vector<vector<int>>>& dp)
    {
        if (i > desti || j > destj) return 0;

        int newRem = (rem + grid[i][j]) % k;

        if (i == desti && j == destj)
            return newRem == 0;

        if (dp[i][j][newRem] != -1)
            return dp[i][j][newRem];

        int down  = find(i + 1, j, desti, destj, grid, newRem, k, dp);
        int right = find(i, j + 1, desti, destj, grid, newRem, k, dp);

        return dp[i][j][newRem] = (down + right) % modVal;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, -1))
        );

        return find(0, 0, n - 1, m - 1, grid, 0, k, dp);
    }
};
