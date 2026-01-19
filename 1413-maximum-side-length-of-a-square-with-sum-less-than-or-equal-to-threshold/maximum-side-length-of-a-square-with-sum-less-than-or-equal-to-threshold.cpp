class Solution {
public:
    int n,m;

    bool isposs(int r,int c,int len,
                vector<vector<int>>& prefixrow,int thr)
    {
        int sum=0;

        for(int i=r-len+1;i<=r;i++)
        {
            int sub = (c-len>=0) ? prefixrow[i][c-len] : 0;
            sum+=(prefixrow[i][c] - sub);
        }

        return sum<=thr;
    }

    int maxSideLength(vector<vector<int>>& grid, int threshold) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> prefixrow = grid;
        vector<vector<int>> prefixcol = grid;

        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                prefixrow[i][j] += prefixrow[i][j-1];

        for(int j=0;j<m;j++)
            for(int i=1;i<n;i++)
                prefixcol[i][j] += prefixcol[i-1][j];

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int maxi = min(i+1,j+1);
                for(int k=1;k<=maxi;k++)
                {
                    if(isposs(i,j,k,prefixrow,threshold))
                        ans = max(ans,k);
                    
                    else
                    break;
                }
            }
        }
        return ans;
    }
};
