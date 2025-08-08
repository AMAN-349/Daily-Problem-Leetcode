class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;

    double find(int n1, int n2) {
        if (n1 <= 0 && n2 <= 0) return 0.5;
        if (n1 <= 0) return 1.0;
        if (n2 <= 0) return 0.0;

        if (dp.count(n1) && dp[n1].count(n2))
            return dp[n1][n2];

        double res = 0;
        res += find(n1 - 100, n2);
        res += find(n1 - 75, n2 - 25);
        res += find(n1 - 50, n2 - 50);
        res += find(n1 - 25, n2 - 75);

        return dp[n1][n2] = 0.25 * res;
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0;  // optimization
        return find(n, n);
    }
};
