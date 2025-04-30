class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (!curr.empty()) {
                    res.push_back(curr);
                    curr.clear();
                }
            } else {
                curr.push_back(nums[i]);
            }
        }
        if (!curr.empty()) res.push_back(curr); 

        int ans = 0;

        for (int i = 0; i < res.size(); i++) {
            int first = -1, last = -1, cnt = 0;
            for (int j = 0; j < res[i].size(); j++) {
                if (res[i][j] < 0) {
                    if (first == -1) first = j;
                    last = j;
                    cnt++;
                }
            }

            if (cnt % 2 == 0) {
                ans = max(ans, (int)res[i].size());
            } else {
                int len1 = res[i].size() - first - 1;
                int len2 = last;
                ans = max(ans, max(len1, len2));
            }
        }

        return ans;
    }
};
