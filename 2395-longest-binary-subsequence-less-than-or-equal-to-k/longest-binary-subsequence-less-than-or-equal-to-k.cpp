class Solution {
public:
    int longestSubsequence(string s, int k) {
        string temp="";
        int p=0;
        int sum=0;
        int n=s.size();
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                temp=s[i]+temp;
                p++;
            }
            else{
                if(sum+pow(2,p)<=k)
                {
                    sum+=pow(2,p);
                    temp=s[i]+temp;
                    p++;
                }
                else{
                    break;
                }
            }
        }
        while(i>=0)
        {
            if(s[i]=='0')
            {
                temp=s[i]+temp;
            }
            i--;
        }
        return temp.size();
    }
};