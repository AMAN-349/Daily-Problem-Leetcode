class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int j=0;
        int i=0;
        map<char,int> m;
        int maxfreq=0;
        int ans=0;
        for(int j=0;j<n;j++)
        {
            m[s[j]]++;
            maxfreq=max(maxfreq,m[s[j]]);
            while((j-i+1)-maxfreq>k)
            {
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};