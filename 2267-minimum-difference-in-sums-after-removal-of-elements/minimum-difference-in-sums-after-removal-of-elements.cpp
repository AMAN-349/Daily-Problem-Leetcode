class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> l; 
        priority_queue<int, vector<int>, greater<int>> r; 

        int n = nums.size() / 3;
        long long left = 0, right = 0;
        long long ans = LLONG_MAX;

        vector<long long> temp(nums.size(), 0);
        for (int i = nums.size() - 1; i >= n; i--) {
            r.push(nums[i]);
            right += nums[i];

            if (r.size() > n) {
                right -= r.top();
                r.pop();
            }

            if (r.size() == n) {
                temp[i] = right;
            }
        }
        for (int i = 0; i <= nums.size() - n - 1; i++) {
            l.push(nums[i]);
            left += nums[i];

            if (l.size() > n) {
                left -= l.top();
                l.pop();
            }

            if (l.size() == n) {
                ans = min(ans, left - temp[i + 1]);
            }
        }

        return ans;
    }
};
