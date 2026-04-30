class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    //int dp[201][201][200];
    long long find(int i,int j,int k,vector<vector<int>>& grid)
    {
        if(k<0) return INT_MIN;
        if(i>=n || j>=m) return INT_MIN;
        if(i==n-1 && j==m-1)
        {
            if(k>=1 || grid[i][j]==0)
            {
                return grid[i][j];
            }
            return INT_MIN;
        }
        if(dp[i][j][k]!=-10)
        {
            return dp[i][j][k];
        }
        int rightsum=grid[i][j]+find(i,j+1,k-(grid[i][j]==0?0:1),grid);
        int downsum=grid[i][j]+find(i+1,j,k-(grid[i][j]==0?0:1),grid);

        return dp[i][j][k]=max(rightsum,downsum);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -10)));
        long long ans=find(0,0,k,grid);
        if(ans<0) return -1;
        return ans;

    }
};