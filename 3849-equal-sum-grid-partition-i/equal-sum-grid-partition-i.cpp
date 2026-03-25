class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& v) {

        int n=v.size();
        int m=v[0].size();

        vector<vector<long long>> grid(n, vector<long long>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = v[i][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                grid[i][j]+=grid[i][j-1];
            }
        }

        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);

        prefix[0]=grid[0][m-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+grid[i][m-1];
        }
        suffix[n-1]=grid[n-1][m-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+grid[i][m-1];
        }

        for(auto i:suffix)
        {
            cout<<i<<" ";
        }

        for(int i=0;i<n-1;i++)
        {
            if(prefix[i]==suffix[i+1])
            {
                return true;
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                grid[j][i]+=grid[j-1][i];
            }
        }

        for(int i=0;i<m-1;i++)
        {
            if(grid[n-1][i]==grid[n-1][m-1]-grid[n-1][i])
            {
                return true;
            }
        }

        return false;



    }
};