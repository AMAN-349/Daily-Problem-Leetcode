class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> dp(m);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int fl=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X')
                {
                    sum++;
                    fl=1;
                }
                else if(grid[i][j]=='Y')
                {
                    sum--;
                }
                dp[j].first|=fl;
                dp[j].second+=sum;

                if(dp[j].first && dp[j].second==0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};