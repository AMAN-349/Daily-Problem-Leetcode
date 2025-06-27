class Solution {
public:
    string res;
    string original;
    int k;

    bool check(const string& pattern) {
        int count = 0, j = 0;
        for (char ch : original) {
            if (ch == pattern[j]) {
                j++;
                if (j == pattern.size()) {
                    count++;
                    j = 0;
                    if (count >= k) return true;
                }
            }
        }
        return false;
    }

    void backtrack(vector<pair<char, int>>& v, string& curr) {
        if (check(curr)) {
            if (curr.size() > res.size() || (curr.size() == res.size() && curr > res)) {
                res = curr;
            }
        }

        if (curr.size() == 7) return;

        for (int i = 0; i < v.size(); i++) {
            if (v[i].second > 0) {
                v[i].second--;
                curr.push_back(v[i].first);
                backtrack(v, curr);
                curr.pop_back();
                v[i].second++;
            }
        }
    }

    string longestSubsequenceRepeatedK(string s, int k_) {
        k = k_;
        original = s;
        map<char, int> freq;
        for (char ch : s) freq[ch]++;

        vector<pair<char, int>> v;
        for (char ch = 'z'; ch >= 'a'; ch--) {
            if (freq[ch] >= k) {
                v.push_back({ch, freq[ch] / k});
            }
        }

        string curr = "";
        backtrack(v, curr);
        return res;
    }
};
