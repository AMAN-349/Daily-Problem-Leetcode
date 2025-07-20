class Solution {
public:

  bool isPal(int i,int j,string s)
  {
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
  }

    bool validPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        int cnt=0;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else{
                return isPal(i,j-1,s) || isPal(i+1,j,s);
            }
        }
        return i<j?false:true;
    }
};