class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<int> zero(n, 0);
        vector<int> one(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == '0') {
                    zero[i] = 1;
                } else {
                    one[i] = 1;
                }
            } else {
                zero[i] = zero[i-1] + (s[i] == '0' ? 1 : 0);
                one[i] = one[i-1] + (s[i] == '1' ? 1 : 0);
            }
        }

        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '1') {
                ans += (long long)zero[i-1] * (zero[n-1] - zero[i]);
            } else {
                ans += (long long)one[i-1] * (one[n-1] - one[i]);
            }
        }

        return ans;
    }
};
