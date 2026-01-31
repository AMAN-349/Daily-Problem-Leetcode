class Solution {
public:
    int n,m;
    int dp[70][70][70][70];
    int find(int r1,int c1,int r2,int c2,vector<vector<int>>& grid)
    {
        if(r1>=n || c1>=m || r2>=n || c2>=m || r1<0 || c1<0 || r2<0 || c2<0)
        {
            return INT_MIN;
        }
        if(dp[r1][c1][r2][c2]!=-1)
        {
            return dp[r1][c1][r2][c2];
        }
        if(r1==n-1 && r2==n-1)
        {
            if(r1==r2 && c1==c2)
            {
                return grid[r1][c1];
            }
            else{
                return grid[r1][c1]+grid[r2][c2];
            }
        }
        int cherry=0;
        
        if(r1==r2 && c1==c2)
        {
            cherry+=grid[r1][c1];
        }
        else{
            cherry+=grid[r1][c1];
            cherry+=grid[r2][c2];
        }
        
        int ans=INT_MIN;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                ans = max(ans,
                    find(r1 + 1, c1 + d1,
                        r2 + 1, c2 + d2,
                        grid)
                );
            }
        }

        if(ans==INT_MIN)
        {
            return dp[r1][c1][r2][c2]=INT_MIN;
        }
        return dp[r1][c1][r2][c2]=(cherry+ans);

    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp, -1, sizeof(dp));
        long long ans=find(0,0,0,m-1,grid);
        return (ans==INT_MIN)?0:ans;
    }
};