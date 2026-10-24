class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int n=nums.size();
        int i=0;
        int j=1;
        long long ans=0;
        if(nums[0]>=mink && nums[0]<=maxk)
        {
            ans++;
        }
        else{
            i=1;
        }
        while(j<n)
        {
            if(nums[j]>=mink && nums[j]<=maxk)
            {
                ans+=(j-i+1);
            }
            else{
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};