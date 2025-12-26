class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    ans[i][j]=(matrix[i][j]=='1')?1:0;
                }
                else{
                    if(matrix[i][j]=='1'){
                        int a = min(ans[i][j-1], min(ans[i-1][j], ans[i-1][j-1])) + 1;
                        ans[i][j] = a;
                    }
                }
            }
        }
        int maxi=0;
        for(auto i:ans)
        {
            for(int j:i)
            {
                maxi=max(maxi,j);
            }
        }
        return maxi*maxi;
    }
};