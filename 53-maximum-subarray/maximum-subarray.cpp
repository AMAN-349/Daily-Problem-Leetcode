class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            int t=nums[i]+nums[i-1];
            nums[i]=max(nums[i],t);
            ans=max(ans,nums[i]);
        }
        return ans;
    }
};