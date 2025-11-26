class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int n=s.size();
        if(n<3)
        {
            return 0;
        }
        int j=0;
        int i=0;
        int ans=0;
        while(m.size()<3 && i<n)
        {
            m[s[i]]++;
            i++;
        }
        if(m.size()<3)
        {
            return 0;
        }
        ans+=(n-i+1);
        cout<<ans<<" ";
        while(j<=n-3)
        {
            m[s[j]]--;
            if(m[s[j]]==0)
            {
                m.erase(s[j]);
            }
            while(m.size()<3 && i<n)
            {
                m[s[i]]++;
                i++;
            }
            if(m.size()==3)
            {
                ans+=(n-i+1);
            }
            j++;
        }
        return ans;
    }
};