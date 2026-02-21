class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int balance = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            balance += (s[i] == '1' ? 1 : -1);

            if (balance == 0) {
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());

        string res = "";
        for (auto &p : parts) res += p;
        return res;
    }
};
