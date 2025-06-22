class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            temp+=s[i];
            if(temp.size()==k)
            {
                ans.push_back(temp);
                temp="";
            }
        }
        while(temp.size()<k && temp.size()>=1)
        {
            temp+=fill;
        }
        if(temp.size()>0)
        ans.push_back(temp);
        return ans;
    }
};