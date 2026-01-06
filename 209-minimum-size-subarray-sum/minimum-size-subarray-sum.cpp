class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=nums[r];
        int ans=INT_MAX;
        while(r<n)
        {
            while(sum>=target)
            {
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
            if(r<n)
            sum+=nums[r];
        }
        return ans==INT_MAX?0:ans;
    }
};