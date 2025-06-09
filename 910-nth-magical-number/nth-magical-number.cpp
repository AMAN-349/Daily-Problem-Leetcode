class Solution {
public:
    int MOD = 1e9 + 7;

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long find(long long m, long long a, long long b) {
        long long lcm = (a / gcd(a, b)) * b;
        return m / a + m / b - m / lcm;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1;
        long long r = 1LL * n * min(a, b); // upper bound
        long long ans = 0;

        while (l <= r) {
            long long m = (l + r) / 2;
            if (find(m, a, b) < n) {
                l = m + 1;
            } else {
                ans = m;
                r = m - 1;
            }
        }

        return ans % MOD;
    }
};
