class Solution {
public:
    string normalizeLower(const string& s) {
        string res;
        for (char c : s) res += tolower(c);
        return res;
    }

    string normalizeVowel(const string& s) {
        string res;
        for (char c : s) {
            char lower = tolower(c);
            if (lower=='a' || lower=='e' || lower=='i' || lower=='o' || lower=='u')
                res += 'a';
            else
                res += lower;
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string,string> loweronly;
        unordered_map<string,string> lowervowel;

        for (auto& w : wordlist) {
            exact.insert(w);

            string lower = normalizeLower(w);
            if (!loweronly.count(lower))
                loweronly[lower] = w;

            string vow = normalizeVowel(w);
            if (!lowervowel.count(vow))
                lowervowel[vow] = w;
        }

        vector<string> ans;
        for (auto& q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = normalizeLower(q);
            if (loweronly.count(lower)) {
                ans.push_back(loweronly[lower]);
                continue;
            }

            string vow = normalizeVowel(q);
            if (lowervowel.count(vow)) {
                ans.push_back(lowervowel[vow]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};
