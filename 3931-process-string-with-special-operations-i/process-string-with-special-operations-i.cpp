class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto i:s)
        {
            if(i>='a' && i<='z')
            {
                ans+=i;
            }
            else if(i=='*' && ans.size()>0)
            {
                ans.pop_back();
            }
            else if(i=='#' && ans.size()>0)
            {
                ans+=ans;
            }
            else{
                if(ans.size()>0)
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};