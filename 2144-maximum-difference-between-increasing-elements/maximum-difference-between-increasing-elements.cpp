class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            mini=min(mini,nums[i]);
            ans=max(ans,nums[i]-mini);
        }
        return ans==0?-1:ans;
    }
};