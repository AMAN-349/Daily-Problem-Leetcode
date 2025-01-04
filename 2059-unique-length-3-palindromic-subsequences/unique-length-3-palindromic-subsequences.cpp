class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> l;
        int ans=0;
        for(auto i:s)
        {
            l.insert(i);
        }
        for(char c:l)
        {
            int i=-1;
            int j=0;
            for(int k=0;k<s.size();k++)
            {
                if(s[k]==c)
                {
                    if(i==-1)
                    {
                        i=k;
                    }
                    j=k;
                }
            }
            set<char> between;
            for(int m=i+1;m<j;m++)
            {
                between.insert(s[m]);
            }
            ans+=between.size();
        }
        return ans;
    }
};