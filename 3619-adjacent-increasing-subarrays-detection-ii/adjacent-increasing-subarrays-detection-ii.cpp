class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,1);
        vector<int> post(n,1);
        for(int i=1;i<n;i++)
        {
            if (nums[i] > nums[i - 1])
            {
                pre[i]=pre[i-1]+1;
            }
        }
        for(int i=n-1;i>0;i--)
        {
            if (nums[i-1] < nums[i])
            {
                post[i-1]=post[i]+1;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int len1=pre[i-1];
            int len2=post[i];
            ans=max(ans,min(len1,len2));
        }
        return ans;
    }
};