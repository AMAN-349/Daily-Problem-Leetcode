class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        string suffix=s;
        int ind=-1;
        string ans="";
        for(int i=0;i<n-1;i++)
        {
            if(!memcmp(s.c_str(),s.c_str()+n-1-i,i+1))
            {
                ind=n-1-i;
            }
        }
        if(ind==-1)
        {
            return "";
        }
        return s.substr(ind);
    }
};