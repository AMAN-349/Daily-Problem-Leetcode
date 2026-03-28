class Solution {
public:

    bool validate(string res,vector<vector<int>>& s)
    {
        int n=s.size();

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(res[i]!=res[j])
                {
                    if(s[i][j])
                    {
                        return false;
                    }
                }

                else {
                    if (i == n-1 || j == n-1) {
                        if (s[i][j] != 1) {
                            return false;
                        }
                    } else {
                        if (s[i][j] != s[i+1][j+1] + 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    string findTheString(vector<vector<int>>& s) {
        int n=s.size();
        int m=s[0].size();
        if(n==1 && m==1)
        {
            if(s[0][0]==1)
            {
                return "a";
            }
            return "";
        }
        string temp="";
        char last='0';
        string ans(n, '0');
        char cur='a';
        for(int i=0;i<n;i++)
        {
            if(ans[i]=='0')
            {
                if(cur>'z')
                {
                    return "";
                }

                ans[i]=cur;

                for(int j=i+1;j<n;j++)
                {
                    if(s[i][j]>0)
                    ans[j]=cur;
                }
                cur++;
            }
        }
        if(validate(ans,s))
        {
            return ans;
        }
        return "";
    }
};