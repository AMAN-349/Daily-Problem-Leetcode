class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=spaces.size();
        int j=0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(j<n &&i==spaces[j])
            {
                ans+=' ';
                j++;
                ans+=s[i];
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};