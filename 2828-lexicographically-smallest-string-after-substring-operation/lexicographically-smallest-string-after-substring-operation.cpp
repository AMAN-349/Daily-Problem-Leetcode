class Solution {
public:
    string smallestString(string s) {
        int n=s.size();
        string temp="";
        int start=-1,end=-1;
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]!='a')
            {
                break;
            }
        }
        if(start!=n)
        start=i;
        end=start;
        i++;
        for(;i<n;i++)
        {
            if(s[i]=='a')
            {
                break;
            }
        }
        end=i-1;
        if(start==n)
        {
            if(s[n-1]=='a')
            {
                s[n-1]='z';
                return s;
            }
            s[n-1]--;
        }
        else{
            for(int it=start;it<=end;it++)
            {
                s[it]--;
            }
        }
        return s;
    }
};