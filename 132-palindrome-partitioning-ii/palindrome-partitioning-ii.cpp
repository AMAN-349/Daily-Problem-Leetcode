class Solution {
public:

    bool isPalindrome(string& s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int find(int i,string& s,vector<int>& dp)
    {
        if(i==s.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int min_cost=INT_MAX;
        string temp="";
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s,i,j)) {
                int res=1+find(j+1,s,dp);
                min_cost=min(min_cost,res);
            }
        }
        return dp[i]=min_cost;
    }

    int minCut(string s) {
        int ans=s.size();
        vector<int> dp(ans,-1);
        int i=0;
        vector<string> temp;
        return find(i,s,dp)-1;
    }
};