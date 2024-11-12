class Solution {
public:

    int find(int temp)
    {
        int cnt=0;
        if(temp==0)
        {
            return 1;
        }
        if(temp<0)
        {
            cnt++;
            temp=-temp;
        }
        while(temp>0)
        {
            cnt++;
            temp/=10;
        }
        return cnt;
    }

    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            int res=0;
            for(int j=0;j<grid.size();j++)
            {
                int temp=grid[j][i];
                int temp2=find(temp);
                res=max(res,temp2);
            }
            ans.push_back(res);
        }
        return ans;
    }
};