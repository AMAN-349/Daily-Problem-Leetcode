class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)
        {
            return s;
        }
        vector<vector<int>> dp(n,vector<int>(n,true));
        string res=string(1,s[0]);
        int ans=0;
        for(int d=1;d<n;d++)
        {
            int i=0;
            int j=d;
            while(i<n && j<n)
            {
                dp[i][j]=(s[i]==s[j]) && dp[i+1][j-1];
                if(dp[i][j])
                {
                    if(j-i+1>ans)
                    {
                        ans=j-i+1;
                        res=s.substr(i,j-i+1);
                    }
                }
                i++;
                j++;
            }
        }
        return res;
    }
};