class Solution {
public:
    int n,m;

    bool isposs(int r,int c,int len,
                vector<vector<int>>& prefixrow,
                vector<vector<int>>& prefixcol,
                vector<vector<int>>& grid)
    {
        set<int> s1, s2, s3;

        for(int i=r-len+1;i<=r;i++)
        {
            int sub = (c-len>=0) ? prefixrow[i][c-len] : 0;
            s1.insert(prefixrow[i][c] - sub);
        }

        for(int j=c-len+1;j<=c;j++)
        {
            int sub = (r-len>=0) ? prefixcol[r-len][j] : 0;
            s2.insert(prefixcol[r][j] - sub);
        }

        int sum=0;
        for(int i=0;i<len;i++)
            sum += grid[r-i][c-i];
        s3.insert(sum);

        sum=0;
        for(int i=0;i<len;i++)
            sum += grid[r-i][c-len+1+i];
        s3.insert(sum);

        if(s1.size()!=1 || s2.size()!=1 || s3.size()!=1) return false;
        return *s1.begin() == *s2.begin() && *s2.begin() == *s3.begin();
    }

    int largestMagicSquare(vector<vector<int>>& grid) {

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

        int ans = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int maxi = min(i+1,j+1);
                for(int k=2;k<=maxi;k++)
                {
                    if(isposs(i,j,k,prefixrow,prefixcol,grid))
                        ans = max(ans,k);
                }
            }
        }
        return ans;
    }
};
