class Solution {
public:
    vector<vector<pair<long long,long long>>> dp;
    long long mod=1e9+7;
    pair<long,long> find(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(i >= n || j >= m)
        return {LLONG_MAX, LLONG_MIN};

        if(i==n-1 && j==m-1)
        {
            return {grid[i][j],grid[i][j]};
        }

        if(dp[i][j].first != LLONG_MAX)
            return dp[i][j];

        auto down = find(i+1, j, n, m, grid);
        auto right = find(i, j+1, n, m, grid);


        vector<long long> v;

        if(down.first != LLONG_MAX){
            v.push_back(grid[i][j]*down.first);
            v.push_back(grid[i][j]*down.second);
        }

        if(right.first!=LLONG_MAX)
        {
            v.push_back(grid[i][j]*right.first);
            v.push_back(grid[i][j]*right.second);
        }

        if(v.empty()) return {LLONG_MAX, LLONG_MIN};

        long long mini = *min_element(v.begin(), v.end());
        long long maxi = *max_element(v.begin(), v.end());

        return dp[i][j]={mini,maxi};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n, vector<pair<long long,long long>>(m, {LLONG_MAX, LLONG_MIN}));

        pair<long,long> ans=find(0,0,n,m,grid);
        long long res = ans.second;
        if(res < 0) return -1;
        return res % mod;
        
    }
};