class Solution {
public:
    string getSortedString(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string target = getSortedString(n);
        for (int i = 0; i < 31; ++i) {
            int power = 1 << i;
            if (getSortedString(power) == target) return true;
        }
        return false;
    }
};
