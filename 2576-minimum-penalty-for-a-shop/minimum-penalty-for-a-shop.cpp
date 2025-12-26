class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (customers[i - 1] == 'N');
        }

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (customers[i] == 'Y');
        }

        int ans = INT_MAX;
        int res = 0;

        for (int i = 0; i <= n; i++) {
            int penalty = prefix[i] + suffix[i];
            if (penalty < ans) {
                ans = penalty;
                res = i;
            }
        }

        return res;
    }
};
