class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> ind(26);

        for (int i = 0; i < n; i++) {
            ind[s[i] - 'A'].push_back(i);
        }

        for (auto& i : ind) {
            i.push_back(n);
        }

        vector<int> pointers(26, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (pointers[j] + 1 < ind[j].size()) {
                    ans += ind[j][pointers[j] + 1] - ind[j][pointers[j]];
                }
            }
            pointers[s[i] - 'A']++;
        }

        return ans;
    }
};
