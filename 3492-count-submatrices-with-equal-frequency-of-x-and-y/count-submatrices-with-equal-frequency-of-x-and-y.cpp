class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        vector<pair<int,int>>dp(m);

        for(auto i:grid)
        {
            int sum=0, fl=0;
            for(int j=0;j<m;j++)
            {
                if(i[j]=='X')
                {
                    fl=1;
                    sum++;
                }
                else if(i[j]=='Y')
                {
                    sum--;
                }
                dp[j].first|=fl;
                dp[j].second+=sum;
                if(dp[j].first && dp[j].second==0)
                {
                    res++;
                }
            }
        }
        return res;
    }
};