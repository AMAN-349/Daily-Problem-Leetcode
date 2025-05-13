class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);
        int MOD = 1e9 + 7;

        for (char ch : s) {
            freq[ch - 'a'] = (freq[ch - 'a'] + 1) % MOD;
        }

        while (t--) {
            int zCount = freq[25];
            freq[25] = 0;

            for (int i = 24; i >= 0; i--) {
                freq[i + 1] = freq[i];
                freq[i] = 0;
            }

            // convert z into a and b 
            if (zCount) {
                freq[0] = (freq[0] + zCount) % MOD;
                freq[1] = (freq[1] + zCount) % MOD;
            }
        }

        int totalLength = 0;
        for (int i = 0; i < 26; i++) {
            totalLength = (totalLength + freq[i]) % MOD;
        }

        return totalLength;
    }
};