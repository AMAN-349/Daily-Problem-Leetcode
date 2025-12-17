class Solution {
public:
    int n;

    long long dfs(int i, int state, int k, vector<int>& prices,
                  vector<vector<vector<long long>>>& dp) {

        if (i == n) {
            return (state == 0 ? 0 : LLONG_MIN / 4);
        }

        if (k == 0) {
            return (state == 0 ? 0 : LLONG_MIN / 4);
        }

        if (dp[i][k][state] != -1)
            return dp[i][k][state];

        long long ans = dfs(i + 1, state, k, prices, dp);

        if (state == 0) {
            ans = max(ans, dfs(i + 1, 1, k, prices, dp) - prices[i]);
            ans = max(ans, dfs(i + 1, 2, k, prices, dp) + prices[i]);
        }
        else if (state == 1) {
            ans = max(ans, dfs(i + 1, 0, k - 1, prices, dp) + prices[i]);
        }
        else {
            ans = max(ans, dfs(i + 1, 0, k - 1, prices, dp) - prices[i]);
        }

        return dp[i][k][state] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, -1))
        );

        return dfs(0, 0, k, prices, dp);
    }
};
