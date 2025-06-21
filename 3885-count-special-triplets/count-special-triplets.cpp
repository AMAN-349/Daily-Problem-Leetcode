class Solution {
public:
    long long mod=1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        map<int,int> prefix;
        map<int,int> suffix;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            suffix[nums[i]]++;
        }
        long long ans=0;
        prefix[nums[0]]++;
        if(suffix[nums[0]])
        {
            suffix[nums[0]]--;
        }
        long long res=0;
        for(int j=1;j<n-1;j++)
        {
            suffix[nums[j]]--;
            long long ans1=prefix[nums[j]*2]%mod;
            long long ans2=suffix[nums[j]*2]%mod;
            res = (res + (1LL * ans1 * ans2) % mod) % mod;
            prefix[nums[j]]++;
        }
        return res;

    }
};