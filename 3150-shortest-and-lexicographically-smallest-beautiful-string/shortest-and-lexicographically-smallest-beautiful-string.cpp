class Solution {
public:

    static bool cmp(const string& s1, const string& s2)
    {
        if (s1.size() == s2.size())
            return s1 < s2;

        return s1.size() < s2.size();
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int cnt=0;
        int i=0;
        int j=0;
        string ans="";
        vector<string> res;
        while(j < n)
        {
            if(s[j] == '1')
                cnt++;

            while((cnt > k || s[i]=='0') && i <= j)
            {
                if(s[i] == '1')
                    cnt--;

                i++;
            }
            if(cnt == k)
            {
                string temp = s.substr(i, j - i + 1);
                res.push_back(temp);
            }

            j++;
        }
        if(res.size()==0) return "";
        sort(res.begin(),res.end(),cmp);
        return res[0];
    }
};