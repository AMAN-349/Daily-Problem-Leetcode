class Solution {
public:
    vector<int> dp;
    bool isvalid(string find)
    {
        if (find[0] == '0') {
            return false;
        }
        if(stoi(find)>=27)
        {
            return false;
        }
        return true;
    }

    int find(int ind,int n,string s)
    {
        if(ind==n)
        {
            return 1;
        }

        if (s[ind] == '0') {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int ways=0;
        ways+=find(ind+1,n,s);

        if(ind+1<n && isvalid(s.substr(ind,2)))
        {
            ways+=find(ind+2,n,s);
        }
        return dp[ind]=ways;


    }

    int numDecodings(string s) {
        int n=s.size();
        int ans=0;
        dp.resize(n,-1);
        return find(0,n,s);
    }
};