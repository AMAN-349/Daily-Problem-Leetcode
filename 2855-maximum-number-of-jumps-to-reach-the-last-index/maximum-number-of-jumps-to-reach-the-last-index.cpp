class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,0);

        for(int i=1;i<n;i++)
        {
            dp[i]=-1;
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]!=-1 && abs(nums[i]-nums[j])<=target)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};