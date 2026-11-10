class Solution {
public:

    int dp[100001];

    int find(int i,vector<int>& costs)
    {
        if(i>=costs.size())
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int ans=INT_MAX;

        ans=min(ans,1+costs[i]+find(i+1,costs));

        if(i+2<=costs.size())
        ans=min(ans,costs[i+1]+4+find(i+2,costs));

        if(i+3<=costs.size())
        ans=min(ans,costs[i+2]+9+find(i+3,costs));

        return dp[i]=ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return find(0,costs);
    }
};