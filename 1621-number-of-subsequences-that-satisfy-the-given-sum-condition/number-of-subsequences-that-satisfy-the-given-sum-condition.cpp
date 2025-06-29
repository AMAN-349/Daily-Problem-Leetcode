class Solution {
public:
    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = 0;
        int mod = 1e9 + 7;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + modPow(2, r - l, mod)) % mod;
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
