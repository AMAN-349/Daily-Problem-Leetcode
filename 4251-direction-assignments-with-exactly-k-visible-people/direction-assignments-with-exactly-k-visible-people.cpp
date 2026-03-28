class Solution {
public:
    long long mod = 1e9 + 7;

    vector<long long> fact, invFact;

    // fast exponentiation
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    // precompute factorial and inverse factorial ONCE
    void precompute(int N) {
        fact.resize(N + 1);
        invFact.resize(N + 1);

        fact[0] = 1;
        for (int i = 1; i <= N; i++)
            fact[i] = fact[i - 1] * i % mod;

        invFact[N] = power(fact[N], mod - 2);

        for (int i = N - 1; i >= 0; i--)
            invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }

    // O(1) nCr
    long long findncr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
    }

    int countVisiblePeople(int n, int pos, int k) {

        precompute(n);   // only up to n needed

        long long ans = 0;

        if (k == 0) return 2;

        for (int i = 0; i <= k; i++) {
            int l = i;
            int r = k - i;

            long long res = 1;

            if (pos >= l && (n - pos - 1) >= r) {
                res = findncr(pos, l) * findncr(n - pos - 1, r) % mod;
                ans = (ans + res) % mod;
            }
        }

        return (ans * 2) % mod;
    }
};