class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
        int r=-1;
        int cnta=0;
        int cntb=0;
        int cntc=0;
        int ans=0;
        while(r<n)
        {
            while((cnta==0 || cntb==0 || cntc==0) && r<n){
                r++;
                if(s[r]=='a')
                {
                    cnta++;
                }
                else if(s[r]=='b')
                {
                    cntb++;
                }
                else{
                    cntc++;
                }
            }
            ans+=(n-r);
            if(s[l]=='a')
            {
                cnta--;
            }
            else if(s[l]=='b')
            {
                cntb--;
            }
            else{
                cntc--;
            }
            l++;
        }
        return ans;
    }
};