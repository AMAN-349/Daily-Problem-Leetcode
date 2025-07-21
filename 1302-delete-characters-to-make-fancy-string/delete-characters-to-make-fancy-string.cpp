class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        
        // Initialize a counter for consecutive characters
        int count = 1; 
        ans += s[0]; // Add the first character to the answer

        for (int i = 1; i < s.size(); i++) {
            // If the current character is the same as the last character in ans
            if (s[i] == ans.back()) {
                count++;
            } else {
                count = 1; // Reset count for a new character
            }

            // Add the current character to ans if count is less than 3
            if (count < 3) {
                ans += s[i];
            }
        }

        return ans;
    }
};
