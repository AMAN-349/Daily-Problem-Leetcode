class Solution {
public:

    int dp[101][101][601];

    int find(vector<string>& strs,int m,int n,int i)
    {
        if(i>=strs.size())
        {
            return 0;
        }
        if(dp[m][n][i]!=-1)
        {
            return dp[m][n][i];
        }
        int zc = count(strs[i].begin(), strs[i].end(), '0');
        int oc = strs[i].size() - zc;
        if(m>=zc && n>=oc)
        {
            return dp[m][n][i]=max(1+find(strs,m-zc,n-oc,i+1),find(strs,m,n,i+1));
        }
        else{
            return dp[m][n][i]=find(strs,m,n,i+1);
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return find(strs,m,n,0);
    }
};