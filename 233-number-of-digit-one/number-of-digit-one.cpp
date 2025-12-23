class Solution {
public:

    int res=0;
    int solve(int m,string s,int idx, int tight,int exclude,int cnt,vector<vector<vector<int>>>& dp)
    {
        if(idx==m)
        {
            return cnt;
        }

        if(dp[idx][tight][cnt]!=-1)
        {
            return dp[idx][tight][cnt];
        }

        int lb=0;
        int ub=(tight==1)?(s[idx]-'0'):9;
        cout<<ub<<" ";
        int ans=0;
        for(int i=lb;i<=ub;i++)
        {
            if(i==1){
                ans+=solve(m,s,idx+1,(tight && i==ub),exclude,cnt+1,dp);
            }
            else{
                ans+=solve(m,s,idx+1,(tight && i==ub),exclude,cnt,dp);
            }
        }
        return dp[idx][tight][cnt]=ans;
    }

    int countDigitOne(int n) {
        string s=to_string(n);
        int m=s.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(2,vector<int>(m+1,-1)));
        return solve(m,s,0,1,1,0,dp);
    }
};