class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (grid[mid][i] >= 0) {
                    l++;
                } else {
                    r--;
                }
            }
            ans += (n - l);
        }
        return ans;
    }
};