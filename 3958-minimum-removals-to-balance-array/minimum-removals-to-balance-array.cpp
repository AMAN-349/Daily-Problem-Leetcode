class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0;
        int r=upper_bound(nums.begin(),nums.end(),nums[0])-nums.begin();
        ans=max(ans,r-l);
        while(r<n)
        {
            while(1LL*nums[l]*k<nums[r])
            {
                l++;
            }
            r++;
            ans=max(ans,r-l);
        }
        return n-ans;
    }
};