class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i;
            long long temp=1LL*nums[l]*k;
            int r=upper_bound(nums.begin(),nums.end(),temp)-nums.begin();
            ans=max(ans,r-l);
        }
        return n-ans;
    }
};