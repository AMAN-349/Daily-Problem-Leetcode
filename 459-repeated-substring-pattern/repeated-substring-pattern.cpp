class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=1;i<=n/2;i++)
        {
            string temp=s.substr(0,i);
            //cout<<temp<<" ";
            string cmp=temp;
            while(cmp.size()<s.size())
            {
                cmp+=temp;
            }
            if(cmp==s)
            return true;
        }
        return false;
    }
};