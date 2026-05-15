class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=INT_MAX;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]>nums[n-1])
            {
                ans=min(ans,nums[m]);
                l=m+1;
            }
            else{
                ans=min(ans,nums[m]);
                h=m-1;
            }
        }
        return ans;
    }
};