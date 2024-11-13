class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long res=0;
        for(int i=0;i<nums.size();i++)
        {
            int low=lower-nums[i];
            int high=upper-nums[i];

            int temp1 = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            int temp2 = upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();

            if (temp1 <= temp2) {
                res += (temp2 - temp1);
            }
        }
        return res;
    }
};