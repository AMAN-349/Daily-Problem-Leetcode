class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int> m;
            unordered_map<int,int> freqCount;
            for(int j=i;j<n;j++)
            {
                char c = s[j];

                if(m[c] > 0) {
                    freqCount[m[c]]--;
                    if(freqCount[m[c]] == 0)
                        freqCount.erase(m[c]);
                }

                m[c]++;
                freqCount[m[c]]++;

                if(freqCount.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};