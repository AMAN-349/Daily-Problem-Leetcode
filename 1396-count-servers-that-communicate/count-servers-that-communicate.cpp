class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        int n=grid.size();
        int m=grid[0].size();

        int total=0;
        for(auto i:grid)
        {
            for(auto j:i)
            {
                total+=j;
            }
        }

        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                cnt+=grid[i][j];
            }
            rows.push_back(cnt);
        }

        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                cnt+=grid[j][i];
            }
            cols.push_back(cnt);
        }

        for(auto i:rows)
        {
            cout<<i<<" ";
        }
        cout<<endl;

        for(auto i:cols)
        {
            cout<<i<<" ";
        }
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) continue;
                if(rows[i]==1 && cols[j]==1)
                {
                    ans++;
                }
            }
        }
        return total-ans;



    }
};