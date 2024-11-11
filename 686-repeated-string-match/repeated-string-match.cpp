class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeatCount = 1;
        string s = a;

        while (s.size() < b.size()) {
            s += a;
            repeatCount++;
        }

        if (s.find(b) != string::npos) {
            return repeatCount;
        }

        s += a;
        repeatCount++;

        if (s.find(b) != string::npos) {
            return repeatCount;
        }

        return -1;
    }
};
