class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for(int i=1;i<n;i++)
        {
            int m=triangle[i].size();
            vector<int> temp(m,1e8);
            for(int j=0;j<m;j++)
            {
                if(j<dp.size()){
                    temp[j]=triangle[i][j]+dp[j];
                }
                if(j-1>=0)
                {
                    temp[j]=min(temp[j],triangle[i][j]+dp[j-1]);
                }
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(auto i:dp)
        {
            ans=min(ans,i);
        }
        return ans;
    }
};