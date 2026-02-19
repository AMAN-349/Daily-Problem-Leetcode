class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int ans=0;
        int r=0;
        char find=s[r]=='0'?'0':'1';
        int prevcnt=0;
        while(s[r]==find)
        {
            prevcnt++;
            r++;
        }
        while(r<n)
        {
            int currcnt=0;
            char next=(find=='0')?'1':'0';
            while(s[r]==next)
            {
                currcnt++;
                r++;
            }
            ans+=min(prevcnt,currcnt);
            prevcnt=currcnt;
            find=next;
        }
        return ans;
    }
};