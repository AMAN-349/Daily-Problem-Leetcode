class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        while(l<r)
        {
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};