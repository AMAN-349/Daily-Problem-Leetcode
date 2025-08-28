class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            int j=i;
            int k=0;
            vector<int> temp;
            while(j<n && k<m)
            {
                temp.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            j=i;
            k=0;
            for(int it: temp)
            {
                ans[j][k]=it;
                j++;
                k++;
            }


        }
        for(int i=1;i<m;i++)
        {
            int j=0;
            int k=i;
            vector<int> temp;
            while(j<n && k<m)
            {
                temp.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(temp.begin(),temp.end());
            j=0;
            k=i;
            for(int it: temp)
            {
                ans[j][k]=it;
                j++;
                k++;
            }


        }
        return ans;
    }
};