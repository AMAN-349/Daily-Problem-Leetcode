class Solution {
public:
    int n,m;
    int dp[101][101][1000];

    bool find(int i,int j,int brace,vector<vector<char>>& grid)
    {
        if(i==n-1 && j==m-1)
        {
            if(brace<0)
            {
                return false;
            }
            if(grid[i][j]=='(')
            {
                brace++;
            }
            else{
                brace--;
            }
            if(brace==0) return true;
            return false;
        }
        if(brace<0)
        {
            return false;
        }
        if(i==n || j==m) return false;

        if(dp[i][j][brace]!=-1)
        {
            return dp[i][j][brace];
        }

        bool ans=false;

        if(grid[i][j]=='(')
        {
            ans|=find(i+1,j,brace+1,grid);
            ans|=find(i,j+1,brace+1,grid);
        }
        else{
            ans|=find(i+1,j,brace-1,grid);
            ans|=find(i,j+1,brace-1,grid);
        }
        return dp[i][j][brace]=ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,grid);
    }
};