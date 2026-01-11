class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = (matrix[i][j] == 1);
                } else if(matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                }
            }
        }

        int res = 0;
        for(auto &row : dp)
            for(int val : row)
                res += val;

        return res;
    }
};
