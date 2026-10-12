class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod=1e9+7;
        vector<long long> ans(k, 0);

        for (int bit = 30; bit >= 0; bit--) {
            int cnt = 0;
            for (int x : nums) {
                if (x & (1LL << bit)) {
                    cnt++;
                }
            }

            for (int i = 0; i < min(cnt, k); i++) {
                ans[i] |= (1LL << bit);
            }
        }

        long long sum = 0;
        for (long long x : ans) {
            sum = (sum+1LL* x * x)%mod;
        }

        return sum;
    }
};