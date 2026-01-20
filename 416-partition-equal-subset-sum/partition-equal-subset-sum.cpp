class Solution {
public:
    vector<vector<int>> dp;
    bool find(int i,int target,vector<int>& nums,int curr)
    {
        if(curr > target) return false;

        if(i==nums.size())
        {
            if(curr==target)
            {
                return true;
            }
            return false;
        }
        if(dp[i][curr]!=-1)
        {
            return (bool)dp[i][curr];
        }
        return dp[i][curr]=find(i+1,target,nums,curr) || find(i+1,target,nums,curr+nums[i]);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        dp.resize(nums.size(),vector<int>(sum/2+1,-1));
        if(sum%2!=0)
        {
            return false;
        }
        return find(0,sum/2,nums,0);
    }
};