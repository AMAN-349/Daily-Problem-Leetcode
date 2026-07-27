class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(auto &i:nums)
        {
            i--;
        }
        sort(nums.begin(),nums.end());
        return nums[n-1]*nums[n-2];
    }
};