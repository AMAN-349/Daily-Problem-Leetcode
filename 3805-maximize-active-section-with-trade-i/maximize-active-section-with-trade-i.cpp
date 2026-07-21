class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ans = 0;
        for (auto c : s) {
            if (c == '1') {
                ans++;
            }
        }

        vector<pair<int, int>> v;
        int i = 0;

        while (i < n) {
            if (s[i] == '0') {
                int first = i;
                while (i < n && s[i] == '0')
                    i++;

                v.push_back({first, i - 1});
            } else {
                i++;
            }
        }
        
        if (v.size() <= 1) return ans;
        int best=0;

        for (int j = 1; j < v.size(); j++) {
            int totalones = 0;
            totalones += (v[j].second - v[j].first + 1);
            totalones += (v[j - 1].second - v[j - 1].first + 1);

            if(totalones>best)
            {
                best=totalones;
            }
        }

        return ans+best;
    }
};