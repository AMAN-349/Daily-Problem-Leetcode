class Solution {
public:

    int find(set<int>& temp2)
    {
        if(temp2.size()==1) return 0;
        int ans=INT_MAX;
        vector<int> v;
        for(auto i:temp2)
        {
            v.push_back(i);
        }
        for(int i=1;i<v.size();i++)
        {
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<=n-k;i++)
        {
            vector<int> temp;
            for(int j=0;j<=m-k;j++)
            {
                set<int> temp2;
                for(int it=i;it<i+k;it++)
                {
                    for(int it2=j;it2<j+k;it2++)
                    {
                        temp2.insert(grid[it][it2]);
                    }
                }
                temp.push_back(find(temp2));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};