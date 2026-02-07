class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='1')
            {
                dp[i]=dp[i-1];
                cnt++;
            }
            else{
                dp[i]=min(dp[i-1]+1,cnt);
            }
        }
        return dp[n];
    }
};