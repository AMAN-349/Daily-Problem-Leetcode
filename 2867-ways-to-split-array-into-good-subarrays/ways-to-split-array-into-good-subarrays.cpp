class Solution {
public:

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        long long ans=1;
        long long mod=1e9+7;
        int prev=-1;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                flag=true;
                if(prev==-1)
                {
                    prev=i;
                    continue;
                }
                ans=1LL*((ans*(i-prev))%mod);
                prev=i;
            }
        }
        if(!flag) return 0;
        return ans;
    }
};