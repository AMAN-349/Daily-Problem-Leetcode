class Solution {
public:
    int n;
    vector<long long> dp;

    long long find(map<int, int>& m, vector<int>& power, int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        long long skip = find(m, power, i + 1);
        long long take = (long long)m[power[i]] * power[i];
        int j = i + 1;
        while (j < n && power[j] - power[i] <= 2) j++;
        take += find(m, power, j);

        return dp[i] = max(skip, take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> m;
        for (auto p : power) m[p]++;
        vector<int> nums;
        for (auto& it : m) nums.push_back(it.first);

        n = nums.size();
        dp.assign(n, -1);

        return find(m, nums, 0);
    }
};
