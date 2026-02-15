class Solution {
public:
    int n;

    int find(int left,int right,string s)
    {
        int ans=0;
        while(left>=0 && right<n && s[left]==s[right])
        {
            ans=max(ans,right-left+1);
            left--;
            right++;
        }
        if(left<0 && right>=n)
        {
            return ans;
        }
        else
        {
            ans++;
        }
        int newleft=left-1;
        int newright=right;
        while(newleft>=0 && newright<n && s[newleft]==s[newright])
        {
            ans=max(ans,newright-newleft+1);
            newleft--;
            newright++;
        }
        newleft=left;
        newright=right+1;
        while(newleft>=0 && newright<n && s[newleft]==s[newright])
        {
            ans=max(ans,newright-newleft+1);
            newleft--;
            newright++;
        }
        return ans;
    }

    int almostPalindromic(string s) {
        n=s.size();
        int ans=0;
        if(n<=2) return n;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,find(i,i,s));
            ans=max(ans,find(i,i+1,s));
        }
        return ans;
    }
};