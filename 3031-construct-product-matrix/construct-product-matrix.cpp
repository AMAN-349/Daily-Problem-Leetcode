class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        vector<vector<int>> prefix(n, vector<int>(m + 1, 1));
        vector<vector<int>> suffix(n, vector<int>(m + 1, 1));

        int temp = 1;

        for (int i = 0; i < n; i++) {
            prefix[i][0] = temp;
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = (1LL * prefix[i][j - 1] * grid[i][j - 1]) % mod;
            }
            temp = prefix[i][m];
        }

        temp = 1;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i][m] = temp;
            for (int j = m - 1; j >= 0; j--) {
                suffix[i][j] = (1LL * suffix[i][j + 1] * grid[i][j]) % mod;
            }
            temp = suffix[i][0];
        }

        vector<vector<int>> ans(n,vector<int>(m,1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j]=(1LL*ans[i][j] * prefix[i][j])%mod;
                ans[i][j]=(1LL*ans[i][j] * suffix[i][j+1])%mod;
            }
        }

        return ans;
    }
};