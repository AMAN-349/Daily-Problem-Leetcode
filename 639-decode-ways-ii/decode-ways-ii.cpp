class Solution {
public:

    vector<int> dp;
    long long mod=1e9+7;

    int find(int ind,int& n,string& s)
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
        int mult=1;
        if(s[ind]=='*')
        {
            mult=9;
        }

        int ways=0;

        ways+=(1LL*mult*find(ind+1,n,s))%mod;

        if(ind+1<n)
        {
            char curr=s[ind];
            char next=s[ind+1];
            int ops=0;
            if(curr=='*')
            {
                if(next=='*')
                {
                    ops=15;
                }
                else{
                    ops++;
                    if(next<='6')
                    {
                        ops++;
                    }
                }
            }
            else{
                if(next=='*')
                {
                    if(curr=='1')
                    {
                        ops+=9;
                    }
                    else if(curr=='2'){
                        ops+=6;
                    }
                }
                else{
                    if (s[ind] == '1' || (s[ind] == '2' && s[ind+1] <= '6'))
                    {
                        ops++;
                    }
                }
            }
            ways+=(1LL*ops*find(ind+2,n,s))%mod;
        }

        return dp[ind]=(ways%mod);


    }

    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return find(0,n,s);
    }
};