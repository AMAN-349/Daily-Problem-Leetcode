class Solution {
public:
    int n,m;
    int dp[1001][1001];

    int find(int i,int j,string& s,string& t)
    {
        if(j>=m)
        {
            return 1;
        }

        if(i>=n)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int ans=0;
        ans+=find(i+1,j,s,t);

        if(s[i]==t[j])
        {
            ans+=find(i+1,j+1,s,t);
        }

        return dp[i][j]=ans;
    }

    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        memset(dp,-1,sizeof(dp));

        return find(0,0,s,t);
    }
};