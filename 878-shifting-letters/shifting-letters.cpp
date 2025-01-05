class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        
        // Calculate cumulative shifts in reverse
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }
        
        // Apply the shifts to the string
        for (int i = 0; i < n; i++) {
            s[i] = 'a' + (s[i] - 'a' + shifts[i]) % 26;
        }
        
        return s;
    }
};
