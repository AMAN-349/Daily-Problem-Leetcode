class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans++;
            }
            i++;
        }
        return ans;
    }
};