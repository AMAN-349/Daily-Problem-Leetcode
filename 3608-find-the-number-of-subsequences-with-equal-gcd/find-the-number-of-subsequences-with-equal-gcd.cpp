class Solution {
public:

    int dp[201][201][201];
    long long mod=1e9+7;

    int find(int i,int n,vector<int>& nums,int gcd1,int gcd2)
    {
        if(i==n)
        {
            if (gcd1 == gcd2 && gcd1 != 0)
                return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)
        {
            return dp[i][gcd1][gcd2];
        }
        long long ans=0;

        ans=(ans+find(i+1,n,nums,gcd1,gcd2))%mod;
        ans=(ans+find(i+1,n,nums,__gcd(gcd1,nums[i]),gcd2))%mod;
        ans=(ans+find(i+1,n,nums,gcd1,__gcd(gcd2,nums[i])))%mod;

        return dp[i][gcd1][gcd2]=ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return find(0,n,nums,0,0);
    }
};