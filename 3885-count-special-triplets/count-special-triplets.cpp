class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> left, right;
        for (int x : nums) right[x]++;

        long long ans = 0;

        long long mod=1e9+7;
        for (int i = 0; i < n; i++) {
            right[nums[i]]--;

            long long need = 2 * nums[i];
            ans = (ans + (1LL * left[need] * right[need]) %mod)%mod;
            left[nums[i]]++;
        }

        return ans;
    }
};
