class Solution {
public:
    
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int find(string s,char a,char b)
    {
        int n=s.size();
        unordered_map<int,int> m;
        m[0]=-1;
        int ans=0;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==a)
            {
                temp++;
                if(m.count(temp))
                {
                    ans=max(ans,i-m[temp]);
                }
                else{
                    m[temp]=i;
                }

            }
            else if(s[i]==b)
            {
                temp--;
                if(m.count(temp))
                {
                    ans=max(ans,i-m[temp]);
                }
                else{
                    m[temp]=i;
                }
            }
            else{
                m.clear();
                m[0]=i;
                temp=0;
            }
        }
        return ans;
    }

    int find2(string s)
    {
        unordered_map<pair<int,int>,int,pair_hash> m;
        int cnta=0;
        int cntb=0;
        int cntc=0;
        int ans=0;
        pair<int,int> temp={0,0};
        m[temp]=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                cnta++;
            }
            else if(s[i]=='b')
            {
                cntb++;
            }
            else{
                cntc++;
            }
            pair<int,int> p={cntb-cnta,cntc-cnta};
            if(m.count(p))
            {
                ans=max(ans,i-m[p]);
            }
            else{
                m[p]=i;
            }
        }
        return ans;
    }

    int longestBalanced(string s) {
        int n=s.size();

        //for 1 distinct element
        int ans=1;
        int res=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                ans++;
                res=max(res,ans);
            }
            else{
                ans=1;
            }
        }

        //for 2 distinct elements
        res=max(res,find(s,'a','b'));
        res=max(res,find(s,'b','c'));
        res=max(res,find(s,'a','c'));

        //for 3 distince elements
        res=max(res,find2(s));
        return res;

    }
};