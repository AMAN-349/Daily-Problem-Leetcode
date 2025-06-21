class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> m;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            m[word[i]]++;
        }

        int res = INT_MAX;
        for (auto it1 : m) {
            int x = it1.second;
            int ans = 0;

            for (auto it2 : m) {
                int freq = it2.second;

                if (freq < x) {
                    ans += freq;  
                }
                else if (freq > x + k) {
                    ans += (freq - (x + k)); 
                }
            }

            res = min(res, ans);
        }

        return res;
    }
};
