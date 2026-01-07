class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //here we use the sliding window technique
        int n=s.size();
        unordered_map<char,int> m;
        int l=0;
        int r=0;
        int ans=0;
        while(r<n)
        {
            m[s[r]]++;
            while(l<r && m[s[r]]>1)
            {
                if(m.find(s[l])!=m.end())
                {
                    m[s[l]]--;
                    if(m[s[l]]==0)
                    {
                        m.erase(s[l]);
                    }
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};