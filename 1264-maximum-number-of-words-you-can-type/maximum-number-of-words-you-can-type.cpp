class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> s(brokenLetters.begin(), brokenLetters.end());
        int cnt=0;
        string temp="";
        bool flag= false;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
                if(!flag)
                {
                    cnt++;
                }
                temp="";
                flag=false;
            }
            else{
                temp+=text[i];
                if(s.count(text[i]))
                {
                    flag=true;
                }
            }
        }
        if(!flag)
        {
            cnt++;
        }
        return cnt;
    }
};