class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int n,m;

    bool isValid(int i,int j)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }

    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(isValid(nx,ny) && grid[nx][ny]==0)
            {
                grid[nx][ny]=1;
                dfs(nx,ny,grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==0)
            dfs(0,i,grid);

            if(grid[n-1][i]==0)
            dfs(n-1,i,grid);

            if(grid[i][0]==0)
            dfs(i,0,grid);

            if(grid[i][m-1]==0)
            dfs(i,m-1,grid);
        }

        for(auto i:grid)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int ans=0;

        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }

        return ans;
    }
};