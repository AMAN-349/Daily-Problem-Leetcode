class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        int cnt=0;
        while(r<n)
        {
            if(nums[r]==1)
            {
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                cnt++;
                while(cnt>k)
                {
                    if(nums[l]==0)
                    {
                        cnt--;
                    }
                    l++;
                }
                ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};