class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            int pos = (2 * (i - 1)) + 1;
            long long temp = (1LL * pos * (pos + 1)) % MOD;
            temp = (temp * ans) % MOD;
            ans = (temp * 500000004) % MOD;  
        }
        return ans;
    }
};
