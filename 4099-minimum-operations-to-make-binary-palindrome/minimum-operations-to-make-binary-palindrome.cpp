class Solution {
public:
    vector<int> pal;

    bool ispal(int x) {
        int rev = 0, tmp = x;
        while (tmp) {
            rev = (rev << 1) | (tmp & 1);
            tmp >>= 1;
        }
        return rev == x;
    }

    Solution() {
        for (int i = 1; i <= 5000; i++) {
            if (ispal(i)) {
                pal.push_back(i);
            }
        }
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            auto it = lower_bound(pal.begin(), pal.end(), x);

            int diff1 = (it != pal.end()) ? abs(*it - x) : INT_MAX;
            int diff2 = (it != pal.begin()) ? abs(*prev(it) - x) : INT_MAX;

            ans.push_back(min(diff1, diff2));
        }

        return ans;
    }
};
