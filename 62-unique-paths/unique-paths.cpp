class Solution {
public:
    vector<vector<int>> dp;
    int find(int i,int j,int m,int n)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans1=find(i+1,j,m,n);
        int ans2=find(i,j+1,m,n);
        return dp[i][j]=ans1+ans2;
    }

    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return find(0,0,m,n);
    }
};