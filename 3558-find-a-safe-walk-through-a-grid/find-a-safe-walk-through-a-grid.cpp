class Solution {
public:
    int n,m;

    vector<int> dx,dy;
    vector<vector<int>> vis;

    int dp[51][51][102];

    bool isValid(int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }

    bool find(int i,int j,vector<vector<int>>& grid, int health)
    {
        cout<<health<<" ";
        if(i==n-1 && j==m-1)
        {
            return health>=1;
        }

        if(health<1) return false;

        if(dp[i][j][health]!=-1) return dp[i][j][health]; 

        bool ans=false;
        vis[i][j]=true;

        for(int k=0;k<4;k++)
        {
            int newx=i+dx[k];
            int newy=j+dy[k];

            if(isValid(newx,newy) && !vis[newx][newy])
            {
                ans|=find(newx,newy,grid,health - grid[newx][newy]);
                if(ans)
                {
                    vis[i][j] = false;
                    return true;
                }
            }
        }

        vis[i][j]=false;

        return dp[i][j][health]=ans;
        
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n=grid.size();
        dx={-1,0,1,0};
        dy={0,1,0,-1};
        m=grid[0].size();
        vis.resize(n,vector<int>(m,0));

        memset(dp,-1,sizeof(dp));

        return find(0,0,grid,health-grid[0][0]);
    }
};