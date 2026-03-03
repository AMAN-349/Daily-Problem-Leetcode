class Solution {
public:

    string find2(string s)
    {
        string ans="";
        int n=s.size();
        for(auto i:s)
        {
            if(i=='0')
            {
                ans+="1";
            }
            else{
                ans+="0";
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string find(int n)
    {
        if(n==1)
        {
            return "0";
        }
        string s1=find(n-1);
        string s2=find2(s1);
        return s1+"1"+s2;
    }

    char findKthBit(int n, int k) {
        string s=find(n);
        return s[k-1];
    }
};