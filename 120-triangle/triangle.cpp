class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> res;
        res.push_back(triangle[0]);
        for(int i=1;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<triangle[i].size();j++)
            {
                int ans=INT_MAX;
                vector<int> v=res[i-1];
                if(j>=0 && j<v.size())
                {
                    ans=min(ans,v[j]+triangle[i][j]);
                }
                if((j-1)>=0 && (j-1)<v.size())
                {
                    ans=min(ans,v[j-1]+triangle[i][j]);
                }
                temp.push_back(ans);
            }
            res.push_back(temp);
        }
        int cnt=INT_MAX;
        for(auto i:res[n-1])
        {
            cnt=min(cnt,i);
        }
        return cnt;
    }
};