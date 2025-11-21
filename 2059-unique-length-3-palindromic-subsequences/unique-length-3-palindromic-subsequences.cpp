class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        int res=0;
        int n=s.size();
        for(char c='a';c<='z';c++)
        {
            int first=-1;
            int last=-1;
            for(int i=0;i<n;i++)
            {
                if(s[i]==c)
                {
                    if(first==-1)
                    {
                        first=i;
                    }
                    else{
                        last=i;
                    }
                }
            }
            if(first!=-1 && last!=-1 && abs(first-last)>1)
            {
                set<char> st;
                for(int i=first+1;i<last;i++)
                {
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }
};