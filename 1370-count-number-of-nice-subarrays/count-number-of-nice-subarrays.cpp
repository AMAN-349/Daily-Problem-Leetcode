class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int count = 0;
        int res = 0;

        while (r < n) {
            if (nums[r] % 2 != 0) {
                count++;
            }

            while (count > k) {
                if (nums[l] % 2 != 0) {
                    count--;
                }
                l++;
            }

            res += (r - l + 1);
            r++;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
