class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[101][10002];
    int find(int i, int m, vector<int>& piles)
    {
        if(i >= n)
            return 0;

        int ans = 0;

        if(dp[i][m]!=-1)
        {
            return dp[i][m];
        }

        for(int k = 1; k <= min(2 * m, n - i); k++)
        {
            int temp = find(i + k, max(m, k), piles);
            int rem=suffix[i]-temp;
            ans = max(ans, rem);
        }

        return dp[i][m]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suffix.resize(n,0);
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=piles[i]+suffix[i+1];
        }
        memset(dp,-1,sizeof(dp));

        return find(0,1,piles);
    }
};