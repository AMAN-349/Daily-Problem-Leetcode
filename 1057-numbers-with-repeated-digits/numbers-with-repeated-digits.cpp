class Solution {
public:
    int m;
    int dp[11][2][2][2][1024];
    int find(int i, string& s, bool tight, bool lz, bool rep, int mask)
    {
        if(i == m)
            return rep ? 1 : 0;

        if(dp[i][tight][lz][rep][mask]!=-1)
        {
            return dp[i][tight][lz][rep][mask];
        }

        int ans = 0;

        int ub = tight ? s[i] - '0' : 9;

        for(int j = 0; j <= ub; j++)
        {
            bool newTight = tight && (j == ub);
            if(lz && j == 0)
            {
                ans += find(i + 1, s, newTight, true, rep, mask);
            }
            else
            {
                bool alreadyUsed = mask & (1 << j);
                ans += find(i + 1,s,newTight,false,rep || alreadyUsed,mask | (1 << j)
                );
            }
        }

        return dp[i][tight][lz][rep][mask]=ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        m=s.size();
        int mask=0;
        memset(dp,-1,sizeof(dp));
        
        return find(0,s,1,1,0,mask);
    }
};