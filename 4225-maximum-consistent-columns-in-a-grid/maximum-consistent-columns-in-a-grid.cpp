class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        vector<pair<int,pair<int,int>>> v;
        int n=grid.size();
        int m=grid[0].size();

        set<pair<int,int>> s;

        for(int i=1;i<m;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                bool flag=true;
                for(int k=0;k<n;k++)
                {
                    if(abs(grid[k][i]-grid[k][j])>limit)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    s.insert({i,j});
                }
            }
        }

        vector<int> dp(m,0);
        dp[0]=1;

        int ans=1;

        for(int i=1;i<m;i++)
        {
            dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {

                if(s.find({i,j})==s.end())
                {
                    continue;
                }

                dp[i]=max(dp[i],dp[j]+1);
                ans=max(ans,dp[i]);
            }
        }

        return ans;
    }
};