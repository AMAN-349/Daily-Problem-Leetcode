class Solution {
public:
    vector<vector<int>> dp;
    int find(int i,int j,int n,int m,string& s1,string& s2)
    {
        if(i==n)
        {
            int temp=0;
            while(j<m)
            {
                temp+=(int)s2[j];
                j++;
            }
            return temp;
        }
        if(j==m)
        {
            int temp=0;
            while(i<n)
            {
                temp+=(int)s1[i];
                i++;
            }
            return temp;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s1[i]==s2[j])
        {
            return dp[i][j]=find(i+1,j+1,n,m,s1,s2);
        }
        return dp[i][j]=min((int)s1[i]+find(i+1,j,n,m,s1,s2),(int)s2[j]+find(i,j+1,n,m,s1,s2));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        dp.resize(n,vector<int>(m,-1));
        return find(0,0,n,m,s1,s2);
    }
};