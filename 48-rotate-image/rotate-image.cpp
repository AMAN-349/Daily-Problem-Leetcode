class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //firstly do transpose
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto& i:matrix)
        {
            reverse(i.begin(),i.end());
        }
    }
};