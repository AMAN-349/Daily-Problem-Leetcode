class Solution {
public:

    bool check(string s)
    {
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='1')
            {
                return false;
            }
        }
        return s[n-1]=='1';
    }

    int numSteps(string s) {
        int n=s.size();
        int cnt=1;
        if(check(s))
        {
            return 0;
        }
        while(true)
        {
            n=s.size();
            if(s[n-1]=='1')
            {
                string temp="";
                int i=n-1;
                int ind=-1;
                while(i>=0 && s[i]=='1')
                {
                    ind=i;
                    i--;
                }
                if(ind<=0)
                {
                    string temp="";
                    temp+="1";
                    for(int i=0;i<n;i++)
                    {
                        temp+="0";
                    }
                    s=temp;
                }
                else{
                    s[ind-1]='1';
                    for(int j=ind;j<n;j++)
                    {
                        s[j]='0';
                    }
                }
                if(check(s))
                {
                    return cnt;
                }
                cout<<s;
                cout<<endl;
            }
            else{
                for(int i=n-2;i>=0;i--)
                {
                    s[i+1]=s[i];
                }
                s[0]='0';
                if(check(s))
                {
                    return cnt;
                }
                cout<<s;
                cout<<endl;
            }
            cnt++;
        }
        return cnt;
    }
};