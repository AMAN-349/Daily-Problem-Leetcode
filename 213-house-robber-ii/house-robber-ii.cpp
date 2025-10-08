class Solution {
public:
    int find(vector<int>& nums,int i,int n,vector<int>& dp)
    {
        if(i==n-1)
        {
            return nums[i];
        }
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans1=find(nums,i+1,n,dp);
        int ans2=nums[i];
        ans2+=find(nums,i+2,n,dp);
        return dp[i]=max(ans1,ans2);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int> dp(n+1,-1);
        int i=0;
        int ans1=find(nums,i,n-1,dp);
        dp.assign(n + 1, -1);
        int ans2=find(nums,i+1,n,dp);
        return max(ans1,ans2);
    }
};