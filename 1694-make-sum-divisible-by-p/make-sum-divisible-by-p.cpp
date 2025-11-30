class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int tofind=sum%p;
        if(tofind==0)
        {
            return 0;
        }
        map<int,int> m;
        m[0]=-1;
        int presum=0;
        int ans=n;
        for(int i=0;i<n;i++)
        {
            presum=(presum+nums[i])%p;
            int curr=(presum-tofind+p)%p;
            if(m.find(curr)!=m.end())
            {
                ans=min(ans,i-m[curr]);
            }
            m[presum]=i;
        }
        if(ans==n) return -1;
        return ans;
    }
};