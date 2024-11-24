class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        long long sum=0;
        int mini=INT_MAX;
        for (int i=0; i<matrix.size(); i++)
        {
            for (int j=0; j<matrix[0].size(); j++)
            {
                if (matrix[i][j]<0)
                {
                    neg+=1;
                }
                sum+= abs(matrix[i][j]);
                if (abs(matrix[i][j]) <mini)
                {
                    mini= abs(matrix[i][j]);
                }
            }
        }
        return(neg%2)?sum-(2*mini):sum;
    }
};