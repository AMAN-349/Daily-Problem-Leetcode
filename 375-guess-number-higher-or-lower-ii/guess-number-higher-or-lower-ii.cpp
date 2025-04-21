class Solution {
public:
    vector<vector<int>> dp;
    int find(int l, int r) {
        if (l >= r) return 0;
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int ans = INT_MAX;

        for (int i = l; i <= r; i++) {
            int cost = i + max(find(l, i - 1), find(i + 1, r));
            ans = min(ans, cost);
        }

        return dp[l][r]=ans;
    }

    int getMoneyAmount(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return find(1, n);
    }
};
