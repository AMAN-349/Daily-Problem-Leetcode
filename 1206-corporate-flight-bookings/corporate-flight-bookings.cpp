class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);

        for (auto &v : bookings) {
            diff[v[0] - 1] += v[2];  
            if (v[1] < n) {
                diff[v[1]] -= v[2];  
            }
        }

        vector<int> ans(n, 0);
        ans[0] = diff[0];  

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + diff[i];
        }

        return ans;
    }
};
