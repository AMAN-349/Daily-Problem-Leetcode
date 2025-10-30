class NumMatrix {
public:
    vector<vector<int>> nums;
    int n, m;

    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        nums = matrix;

        for (int j = 1; j < m; j++)
            nums[0][j] += nums[0][j - 1];

        for (int i = 1; i < n; i++)
            nums[i][0] += nums[i - 1][0];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                nums[i][j] += nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = nums[row2][col2];
        if (col1 > 0) ans -= nums[row2][col1 - 1];
        if (row1 > 0) ans -= nums[row1 - 1][col2];
        if (row1 > 0 && col1 > 0) ans += nums[row1 - 1][col1 - 1];
        return ans;
    }
};
