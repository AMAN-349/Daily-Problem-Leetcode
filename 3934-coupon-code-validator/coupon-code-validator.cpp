class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string, vector<string>> mp;

        auto isValidCode = [&](const string& s) {
            if (s.empty()) return false;
            for (char c : s) {
                if (!isalnum(c) && c != '_')
                    return false;
            }
            return true;
        };

        unordered_set<string> validBusiness = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (validBusiness.count(businessLine[i]) == 0) continue;

            mp[businessLine[i]].push_back(code[i]);
        }

        vector<string> result;

        for (const string& b : order) {
            auto& v = mp[b];
            sort(v.begin(), v.end());
            for (const string& c : v)
                result.push_back(c);
        }

        return result;
    }
};