class Solution {
public:

    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second<b.second;
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        map<char,pair<int,int>> m;
        vector<string> ans;

        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(!m.count(ch))
            {
                m[ch]={i,i};
            }
            else{
                m[ch].second=i;
            }
        }

        set<pair<int,int>> v;
        for(auto i:m)
        {
            int st=i.second.first;
            int en=i.second.second;
            char ch=s[st];

            bool valid = true;

            int j = st;

            while (j <= en)
            {
                int first = m[s[j]].first;
                int last = m[s[j]].second;

                if (first < st)
                {
                    valid = false;
                    break;
                }

                en = max(en, last);
                j++;
            }

            if (valid)
            {
                v.insert({st, en});
            }
        }
        for(auto i:v)
        {
            cout<<i.first<<" "<<i.second;
            cout<<endl;
        }
        vector<pair<int,int>> fin;
        for(auto i:v)
        {
            fin.push_back(i);
        }
        sort(fin.begin(),fin.end(),cmp);
        int last=-1;

        for(auto i:fin)
        {
            int st=i.first;
            int en=i.second;
            if(st>last){
                ans.push_back(s.substr(st,en-st+1));
                last=en;
            }
        }

        if (ans.size() == 0) {
            return vector<string>{s};
        }

        return ans;

    }
};