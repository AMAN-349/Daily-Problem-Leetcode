class Solution {
public:
    int n;
    int dp[50][50][50][50];
    int find(int r1,int c1,int r2,int c2,vector<vector<int>>& grid)
    {
        if(r1>=n || c1>=n || r2>=n || c2>=n)
        {
            return INT_MIN;
        }
        if(dp[r1][c1][r2][c2]!=-1)
        {
            return dp[r1][c1][r2][c2];
        }
        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(r1==n-1 && c1==n-1 && r2==n-1 && c2==n-1)
        {
            return grid[r1][c1]==1;
        }
        int q1=grid[r1][c1];
        int q2=grid[r2][c2];
        int cherry=0;
        if(r1==r2 && c1==c2)
        {
            cherry+=grid[r1][c1];
            grid[r1][c1]=0;
        }
        else{
            cherry+=grid[r1][c1];
            grid[r1][c1]=0;
            cherry+=grid[r2][c2];
            grid[r2][c2]=0;
        }
        int ans=0;
        int p1p2down=find(r1+1,c1,r2+1,c2,grid);
        int p1p2right=find(r1,c1+1,r2,c2+1,grid);
        int p1rightp2down=find(r1,c1+1,r2+1,c2,grid);
        int p1downp2right=find(r1+1,c1,r2,c2+1,grid);

        grid[r1][c1]=q1;
        grid[r2][c2]=q2;

        int sum=max({p1p2down,p1p2right,p1rightp2down,p1downp2right});
        if(sum==INT_MIN)
        {
            return dp[r1][c1][r2][c2]=INT_MIN;
        }
        return dp[r1][c1][r2][c2]=(cherry+sum);

    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp, -1, sizeof(dp));
        long long ans=find(0,0,0,0,grid);
        return (ans==INT_MIN)?0:ans;
    }
};