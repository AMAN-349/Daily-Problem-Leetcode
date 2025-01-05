class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n + 1, 0); // Use an extra space for boundary management
        
        // Apply shift ranges to the prefix sum array
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                v[start] += 1;
                v[end + 1] -= 1;
            } else {
                v[start] -= 1;
                v[end + 1] += 1;
            }
        }
        
        // Compute the prefix sum
        for (int i = 1; i < n; i++) {
            v[i] += v[i - 1];
        }
        
        // Apply the shifts to the string
        string ans = "";
        for (int i = 0; i < n; i++) {
            int shift = v[i] % 26; // Ensure the shift wraps within 26
            int newChar = s[i] - 'a' + shift;
            
            // Handle wrap-around
            if (newChar < 0) {
                newChar += 26;
            } else if (newChar >= 26) {
                newChar -= 26;
            }
            
            ans += ('a' + newChar);
        }
        
        return ans;
    }
};
