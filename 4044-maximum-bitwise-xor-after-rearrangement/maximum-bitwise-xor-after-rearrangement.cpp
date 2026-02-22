class Solution {
public:
    string maximumXor(string s, string t) {
        unordered_map<char,int> m;
        for(auto i:t)
        {
            m[i]++;
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            int curr=s[i];
            if(curr=='1')
            {
                if(m.find('0')!=m.end())
                {
                    m['0']--;
                    if(m['0']==0)
                    {
                        m.erase('0');
                    }
                    ans+="1";
                }
                else{
                    ans+="0";
                }
            }
            else
            {
                if(m.find('1')!=m.end())
                {
                    m['1']--;
                    if(m['1']==0)
                    {
                        m.erase('1');
                    }
                    ans+="1";
                }
                else{
                    ans+="0";
                }
            }
        }
        return ans;
    }
};