class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& v, int i, int j) {
        if (j - i + 1 < 3) return 0; 
        if (j - i + 1 == 3) return v[i] * v[i+1] * v[j]; 

        if (dp[i][j] != -1) return dp[i][j]; 

        int ans = INT_MAX;

        
        for (int k = i + 1; k < j; k++) {
            int cost = v[i] * v[k] * v[j];  
            cost += solve(v, i, k);          
            cost += solve(v, k, j);         
            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(values, 0, n-1);
    }
};
