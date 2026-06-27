class Solution {
public:
    long long mod = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m=l;
        l=1;
        r=(r-m+1);

        int dp[2001][2001][2];
        memset(dp,-1,sizeof(dp));

        //base case if i==n return 1

        for(int prev=l;prev<=r;prev++)
        {
            dp[n][prev][0]=1;
            dp[n][prev][1]=1;
        }

        for(int i=n-1;i>0;i--)
        {
            vector<int> cumsum0(r+1,0);
            vector<int> cumsum1(r+1,0);

            for(int prev=l;prev<=r;prev++)
            {
                cumsum0[prev]=(cumsum0[prev-1]+dp[i+1][prev][0])%mod;
                cumsum1[prev]=(cumsum1[prev-1]+dp[i+1][prev][1])%mod;
            }

            for(int prev=l;prev<=r;prev++)
            {
                dp[i][prev][1]=(cumsum0[r]-cumsum0[prev]+mod)%mod;
                dp[i][prev][0]=(cumsum1[prev-1])%mod;
            }
        }

        int res=0;

        for(int prev=l;prev<=r;prev++)
        {
            res=(res+dp[1][prev][0])%mod;
            res=(res+dp[1][prev][1])%mod;
        }

        return res;
    }
};