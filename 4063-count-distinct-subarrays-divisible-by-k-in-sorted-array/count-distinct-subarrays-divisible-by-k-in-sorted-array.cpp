class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        long long ans=0;
        long long sum=0;
        for(auto i:nums)
        {
            sum+=i;
            int mod=sum%k;
            ans+=m[mod];
            m[mod]++;
        }
        for(int i=0;i<n;)
        {
            int j=i;
            while(j<n && nums[i]==nums[j])
            {
                j++;
            }
            int len=j-i;
            for(int p=1;p<len;p++)
            {
                if((1LL*p*nums[i])%k==0)
                {
                    ans-=(len-p);
                }
            }
            i=j;
        }
        return ans;
    }
};