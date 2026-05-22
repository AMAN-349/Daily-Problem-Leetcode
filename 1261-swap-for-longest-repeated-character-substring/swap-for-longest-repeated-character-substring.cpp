class Solution {
public:

    int find(string text,pair<int,int>& res)
    {
        int n=text.size();
        string s = text.substr(res.first, res.second - res.first + 1);
        cout<<s<<" ";
        int ans=s.size();
        unordered_map<char,int> m2;
        for(auto i:s)
        {
            m2[i]++;
        }
        if(ans==2 && m2.size()==2)
        {
            char tofind=s[0];
            for(int k=(res.second+1);k<n;k++)
            {
                if(text[k]==tofind)
                {
                    return ans;
                }
            }
            for(int k=0;k<res.first;k++)
            {
                if(text[k]==tofind)
                {
                    return ans;
                }
            }
            tofind=s[1];
            for(int k=(res.second+1);k<n;k++)
            {
                if(text[k]==tofind)
                {
                    return ans;
                }
            }
            for(int k=0;k<res.first;k++)
            {
                if(text[k]==tofind)
                {
                    return ans;
                }
            }
            return ans-1;

        }
        char target='#';
        char tofind='@';
        for(auto i:m2)
        {
            if(i.second==1)
            {
                target=i.first;
            }
            else{
                tofind=i.first;
            }
        }
        if(target=='#') return ans;
        for(int k=(res.second+1);k<n;k++)
        {
            if(text[k]==tofind)
            {
                return ans;
            }
        }
        for(int k=0;k<res.first;k++)
        {
            if(text[k]==tofind)
            {
                return ans;
            }
        }
        return ans-1;
    }

    int maxRepOpt1(string text) {
        int n=text.size();
        if(n==1) return 1;
        map<char,int> m;
        int ans=0;
        int j=0;
        pair<int,int> res;
        for(int i=0;i<n;i++)
        {
            m[text[i]]++;
            while(m.size()>2 || (m.size()==2 && (m.begin()->second>1 && prev(m.end())->second>1)))
            {
                m[text[j]]--;
                if(m[text[j]]==0) m.erase(text[j]);
                j++;
            }
            int cnt=(i-j+1);
            if(cnt>=ans)
            {
                res={j,i};
                ans=max(ans,find(text,res));
            }
        }
        return ans;
    }
};