class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //here we want (sum-k)%p==0
        //so sum%p=k%p
        //means we have to find minimum subarray of mod sum%p
        int n=nums.size();
        map<int,int> m;
        m[0]=-1;
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum%p==0) return 0;
        int tofind=sum%p;
        int ans=INT_MAX;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=(temp+nums[i])%p;
            int target=(temp-tofind+p)%p;
            if(m.count(target))
            {
                ans=min(ans,i-m[target]);
            }
            m[temp]=i;
            
        }
        if(ans==INT_MAX || ans==n) return -1;
        return ans;
    }
};