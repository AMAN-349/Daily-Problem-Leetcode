class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.size() - 1;

        while (i >= 0 &&
              (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
               s[i] == 'o' || s[i] == 'u')) {
            i--;
        }

        return s.substr(0, i + 1);
    }
};