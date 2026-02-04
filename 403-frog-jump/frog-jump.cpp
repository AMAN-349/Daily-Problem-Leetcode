class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool find(int i, int lastjump, vector<int>& stones, unordered_map<int,int>& m)
    {
        if (i == n-1) return true;
        if (lastjump <= 0) return false;

        bool ans = false;

        if(dp[i][lastjump]!=-1)
        {
            return dp[i][lastjump];
        }

        int jump1 = stones[i] + lastjump;
        if (m.count(jump1)) {
            ans |= find(m[jump1], lastjump, stones, m);
        }

        int jump2 = stones[i] + lastjump - 1;
        if (lastjump > 1 && m.count(jump2)) {
            ans |= find(m[jump2], lastjump - 1, stones, m);
        }

        int jump3 = stones[i] + lastjump + 1;
        if (m.count(jump3)) {
            ans |= find(m[jump3], lastjump + 1, stones, m);
        }

        return dp[i][lastjump]=ans;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;
        for (int i = 0; i < stones.size(); i++) {
            m[stones[i]] = i;
        }

        n = stones.size();
        dp.resize(n,vector<int>(n,-1));
        if (n < 2 || stones[1] != 1) return false;
        return find(1, 1, stones, m);
    }
};
