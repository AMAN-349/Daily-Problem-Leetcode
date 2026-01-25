class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int ans=INT_MAX;
        k--;
        for(int j=k;j<n;j++)
        {
            mini=INT_MAX;
            maxi=INT_MIN;
            for(int i=j-k;i<=j;i++)
            {
                mini=min(mini,nums[i]);
                maxi=max(maxi,nums[i]);
            }
            ans=min(ans,maxi-mini);
        }
        return ans;
        
    }
};