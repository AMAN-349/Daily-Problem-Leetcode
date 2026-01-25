class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                ans=i;
            }
        }
        return ans;
    }
};