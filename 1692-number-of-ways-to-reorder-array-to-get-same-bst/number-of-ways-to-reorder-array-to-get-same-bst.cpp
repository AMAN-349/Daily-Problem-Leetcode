
class Solution {
public:
    static const long long MOD = 1000000007;
    vector<vector<long long>> comb;

    void precompute(int n) {
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] +
                              comb[i - 1][j]) % MOD;
            }
        }
    }

    long long find(vector<int>& nums) {
        if (nums.size() <= 2)
            return 1;

        int root = nums[0];
        vector<int> left, right;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        int l = left.size();
        int r = right.size();

        long long ways = comb[l + r][r];

        ways = ways * find(left) % MOD;
        ways = ways * find(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        precompute(nums.size());
        return (find(nums) - 1 + MOD) % MOD;
    }
};