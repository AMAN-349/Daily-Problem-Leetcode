class Solution {
public:
    int n,m;
    int dp[500][500][2];
    long long mod=1e9+7;

    long long find(int i,int j,int dir,vector<vector<int>>& grid)
    {
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return 0;
        }
        if(i==n-1 && j==m-1)
        {
            return 1;
        }
        if(dp[i][j][dir]!=-1)
        {
            return dp[i][j][dir];
        }
        long long ans=0;
        if(grid[i][j]==1)
        {
            if(dir==0)
            {
                ans=(ans+find(i+1,j,1,grid))%mod;
            }
            else{
                ans=(ans+find(i,j+1,0,grid))%mod;
            }
        }
        else{
            ans=(ans+find(i+1,j,1,grid))%mod;
            ans=(ans+find(i,j+1,0,grid))%mod;
        }
        return dp[i][j][dir]=(ans%mod);
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        if(n==1 && m==1)
        {
            return 1;
        }

        long long ans=find(0,1,0,grid)+find(1,0,1,grid);
        return ans%mod;

    }
};