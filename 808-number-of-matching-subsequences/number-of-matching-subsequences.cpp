class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        unordered_map<char,set<int>> m;
        for(int i=0;i<n;i++)
        {
            m[s[i]].insert(i);
        }
        int ans=0;
        for(auto& i:words)
        {
            string& temp=i;
            if (m.find(temp[0]) == m.end()) continue;
            int curr=*(m[temp[0]].begin());
            int j;
            for(j=1;j<temp.size();j++)
            {
                set<int>& st=m[temp[j]];
                auto ind = st.upper_bound(curr);
                if(ind==st.end())
                {
                    break;
                }
                curr=*ind;
            }
            if(j==temp.size())
            {
                ans++;
            }
        }
        return ans;
    }
};