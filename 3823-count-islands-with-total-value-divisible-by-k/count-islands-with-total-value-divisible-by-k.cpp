class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int n,m;

    bool isValid(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }

    long long dfs(int i,int j,vector<vector<int>>& grid)
    {
        long long ans=grid[i][j];
        grid[i][j]=0;

        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(isValid(nx,ny) && grid[nx][ny]>0)
            {
                ans+=dfs(nx,ny,grid);
            }
        }

        return ans;

        
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                {
                    long long temp=dfs(i,j,grid);
                    if(temp%k==0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};