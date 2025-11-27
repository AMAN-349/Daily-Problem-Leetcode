class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        for(int i=0;i<n;i++)
        {
            if(!memcmp(s.c_str(),rev.c_str()+i,n-i))
            {
                return rev.substr(0,i)+s;
            }
        }
        return "";
    }
    //to check prefix and suffix without O(n) we use cmp if match it returns 0
};