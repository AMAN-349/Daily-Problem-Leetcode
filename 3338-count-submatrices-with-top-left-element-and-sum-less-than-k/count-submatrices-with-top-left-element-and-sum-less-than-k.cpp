class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                grid[j][i]+=grid[j-1][i];
            }
        }
        int ans=0;
        for(auto i:grid)
        {
            for(auto j:i)
            {
                if(j<=k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};