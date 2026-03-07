class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        int i=0;
        int ans=0;
        int last=-1;
        for(;i<n;)
        {
            //check for odd length pal
            int l=i-1;
            int r=i+1;
            int flag=false;
            while(l>last && r<n && s[l]==s[r])
            {
                if(r-l+1>=k){
                    last=r;
                    flag=true;
                    break;
                }
                l--;
                r++;
            }
            if(flag)
            {
                cout<<l<<" "<<r;
                cout<<endl;
                ans++;
                i+=k;
                continue;
            }

            //check for even length pal
            l=i;
            r=i+1;
            flag=false;
            while(l>last && r<n && s[l]==s[r])
            {
                if(r-l+1>=k){
                    last=r;
                    flag=true;
                    break;
                }
                l--;
                r++;
            }
            if(flag)
            {
                cout<<l<<" "<<r;
                cout<<endl;
                ans++;
                i+=k;
                continue;
            }
            
            i++;

        }
        return ans;

    }
};