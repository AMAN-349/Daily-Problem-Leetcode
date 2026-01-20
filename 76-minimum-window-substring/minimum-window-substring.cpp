class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();

        unordered_map<int,int> m1,m2;
        for(auto i:t)
        {
            m1[i]++;
        }

        int i=0;
        int j=0;
        int start=-1;
        int minlen=INT_MAX;
        int count=0;
        while(j<n)
        {
            if(m1.find(s[j])!=m1.end())
            {
                m2[s[j]]++;
                if(m2[s[j]]<=m1[s[j]])
                {
                    count++;
                }
                while(count==m)
                {
                    if(j-i+1<minlen)
                    {
                        start=i;
                        minlen=j-i+1;
                    }

                    if(m1.find(s[i])!=m1.end())
                    {
                        m2[s[i]]--;

                        if (m2[s[i]] < m1[s[i]]) {
                            count--;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(start==-1) return "";
        string ans=s.substr(start,minlen);
        return ans;
    }
};