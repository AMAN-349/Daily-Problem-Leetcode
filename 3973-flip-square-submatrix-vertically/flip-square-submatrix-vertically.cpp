class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> v;
        for(int i=x;i<x+k;i++)
        {
            vector<int> temp;
            for(int j=y;j<y+k;j++)
            {
                temp.push_back(grid[i][j]);
            }
            v.push_back(temp);
        }
        reverse(v.begin(),v.end());

        int r=-1;
        int c=0;
        for(int i=x;i<x+k;i++)
        {
            r++;
            c=0;
            for(int j=y;j<y+k;j++)
            {
                grid[i][j]=v[r][c++];
            }
        }
        return grid;
    }
};