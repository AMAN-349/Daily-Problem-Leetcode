class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;

        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        long long sum = 0;
        int res = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                sum += i;
                if (sum > n) break;
                if (isPrime[sum]) {
                    res = sum;
                }
            }
        }

        return res;
    }
};
