class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        int n=s.size();
        long long cnt=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
            else{
                long long temp=(cnt%mod * (cnt+1)% mod)%mod;
                ans+=temp/2;
                cnt=0;
            }
        }
        long long temp=(cnt%mod * (cnt+1)% mod)%mod;
        ans+=temp/2;
        return ans;
    }
};