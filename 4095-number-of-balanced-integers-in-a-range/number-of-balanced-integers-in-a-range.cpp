class Solution {
public:
    long long dp[16][2][271];
    const int OFFSET = 135;
    long long find(long long high,int tight,long long diff,int i,string s)
    {
        if(i==s.size())
        {
            if(diff==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][tight][diff+OFFSET]!=-1)
        {
            return dp[i][tight][diff+OFFSET];
        }
        int range=(tight==1)?(s[i]-'0'):9;
        long long ans=0;
        for(int j = 0; j <= range; j++)
        {
            long long tem = diff;
            if(i % 2 == 0)
                tem += j;
            else
                tem -= j;

            ans += find(high, tight && (j == range), tem, i + 1, s);
        }

        return dp[i][tight][diff+OFFSET]=ans;
    }

    long long countBalanced(long long low, long long high) {
        memset(dp, -1, sizeof(dp));
        string s=to_string(high);
        int i=0;
        int tight=1;
        long long temp=find(high,tight,0,i,s);
        memset(dp, -1, sizeof(dp));
        string s2=to_string(low-1);
        i=0;
        long long temp2=find(high,tight,0,i,s2);
        return temp-temp2;
    }
};