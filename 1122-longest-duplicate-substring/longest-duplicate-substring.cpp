class Solution {
public:
    string find_dup(string& s,int len)
    {
        int n=s.size();
        int sp=0;
        int ep=len;

        long long mod=1e9+7;
        long long p=31;

        long long mod1=1e9+9;
        long long p1=29;

        long long pw=1,pw1=1;
        long long chash=0,chash1=0;

        set<pair<int,int>> mp;

        for(int i=len-1;i>=0;i--)
        {
            chash=(chash+((s[i]-'a'+1)*pw)%mod)%mod;
            chash1=(chash1+((s[i]-'a'+1)*pw1)%mod1)%mod1;

            if(i>0)
            {
                pw=(pw*p)%mod;
                pw1=(pw1*p1)%mod1;
            }
        }

        mp.insert({chash,chash1});
        while(ep<n)
        {
            chash=(chash-((s[sp]-'a'+1)*pw)%mod+mod)%mod;
            chash=(chash*p)%mod;
            chash=(chash+(s[ep]-'a'+1))%mod;

            chash1=(chash1-((s[sp]-'a'+1)*pw1)%mod1+mod1)%mod1;
            chash1=(chash1*p1)%mod1;
            chash1=(chash1+(s[ep]-'a'+1))%mod1;

            if(mp.find({chash,chash1})!=mp.end())
            {
                return s.substr(sp+1, len);
            }
            else
            {
                mp.insert({chash,chash1});
            }

            sp++;
            ep++;
        }

        return "";
    }

    string longestDupSubstring(string s) {

        int n=s.size();

        int l=1;
        int r=n-1;

        string res="";

        while(l<=r)
        {
            int m=(l+r)/2;

            string ans=find_dup(s,m);

            if(!ans.empty())
            {
                res=ans;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }

        return res;
    }
};