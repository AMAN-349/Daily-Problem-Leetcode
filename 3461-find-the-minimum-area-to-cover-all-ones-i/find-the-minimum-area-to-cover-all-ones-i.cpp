class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top=-1;
        int bottom=-1;
        int left=-1;
        int right=-1;
        int n=grid.size();
        int m=grid[0].size();
        int flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    flag=true;
                    top=i;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        flag=false;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    flag=true;
                    bottom=i;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        flag=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                {
                    flag=true;
                    left=i;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        flag=false;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1)
                {
                    flag=true;
                    right=i;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        int len=right-left+1;
        int brea=bottom-top+1;
        return len*brea;
    }
};