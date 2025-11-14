class Solution {
public:

    void solve(vector<vector<int>>& mat,int x1,int y1,int x2,int y2)
    {
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                mat[i][j]+=1;
            }
        }
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(auto i:queries)
        {
            solve(mat,i[0],i[1],i[2],i[3]);
        }
        return mat;
    }
};