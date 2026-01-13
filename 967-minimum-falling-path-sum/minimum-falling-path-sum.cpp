class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp=matrix;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int top=INT_MAX;
                int topleft=INT_MAX;
                int topright=INT_MAX;
                top=dp[i-1][j];
                if(j-1>=0)
                {
                    topleft=dp[i-1][j-1];
                }
                if(j+1<m)
                {
                    topright=dp[i-1][j+1];
                }
                dp[i][j]+=min({top,topleft,topright});
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};