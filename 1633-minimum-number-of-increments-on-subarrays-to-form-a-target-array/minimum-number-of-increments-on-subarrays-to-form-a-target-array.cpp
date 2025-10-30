class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                ans+=nums[i]-nums[i-1];
            }
        }
        return ans;         
    }
};