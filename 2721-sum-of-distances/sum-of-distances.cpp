class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int k = idx.size();

            vector<long long> pref(k, 0);
            pref[0] = idx[0];
            for (int i = 1; i < k; i++) {
                pref[i] = pref[i - 1] + idx[i];
            }

            for (int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)idx[i] * i - pref[i - 1];
                }

                if (i < k - 1) {
                    right = (pref[k - 1] - pref[i]) - (long long)idx[i] * (k - i - 1);
                }

                ans[idx[i]] = left + right;
            }
        }

        return ans;
    }
};