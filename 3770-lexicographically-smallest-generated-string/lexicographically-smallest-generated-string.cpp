class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        int sz=(n+m-1);

        string s(sz,'a');
        vector<int> fixed(n+m-1,0);

        for(int i=0;i<n;i++)
        {
            if(str1[i]=='T')
            {
                for(int j=i;j<i+m;j++)
                {
                    if(fixed[j] && s[j]!=str2[j-i])
                    {
                        return "";
                    }
                    else{
                        fixed[j]=1;
                        s[j]=str2[j-i];
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(str1[i]=='F')
            {
                bool flag=false;
                int start=i;
                int end=i+m;
                int idx=-1;
                for(int j=end-1;j>=start;j--)
                {
                    if(str2[j-i]!=s[j])
                    {
                        flag=true;
                    }
                    if(idx==-1 && !fixed[j])
                    {
                        idx=j;
                    }
                }
                if(flag)
                {
                    continue;
                }
                else if(idx!=-1)
                {
                    s[idx]='b';
                }
                else{
                    return "";
                }
            }
        }

        return s;




    }
};