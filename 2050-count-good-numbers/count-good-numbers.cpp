class Solution {
public:
    const int mod = 1e9 + 7;

    int binexp(long long a, long long b) {
        long long res = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long pow5, pow4;
        if (n % 2 == 0) {
            pow5 = binexp(5, n / 2);
            pow4 = binexp(4, n / 2);
        } else {
            long long cnt = n / 2;
            pow5 = binexp(5, cnt + 1);
            pow4 = binexp(4, cnt);
        }
        return (pow5 * pow4) % mod;
    }
};
