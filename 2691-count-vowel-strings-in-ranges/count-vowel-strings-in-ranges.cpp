class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> s = {'a', 'e', 'i', 'o', 'u'};
        vector<int> prefix(words.size(),0);
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            if(s.find(temp[0])!=s.end() && s.find(temp[temp.size()-1])!=s.end())
            {
                cnt++;
            }
            prefix[i]=cnt;
        }
        vector<int> ans;
        for(auto i:queries)
        {
            int l=i[0];
            int r=i[1];
            if(l<=0) ans.push_back(prefix[r]);
            else
            ans.push_back(prefix[r]-prefix[(l-1)]);
        }
        return ans;
    }
};