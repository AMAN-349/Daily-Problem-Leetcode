class Solution {
public:

    static bool cmp(pair<char,int> p1,pair<char,int> p2)
    {
        return p1.second<p2.second;
    }

    string customSortString(string order, string s) {
        vector<char> f(26,INT_MAX);
        for(int i=0;i<order.size();i++)
        {
            f[order[i]-'a']=i;
        }
        vector<pair<char,int>> v;
        for(int i=0;i<s.size();i++)
        {
            v.push_back({s[i],f[s[i]-'a']});
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(auto i:v)
        {
            ans+=i.first;
        }
        return ans;
        

    }
};