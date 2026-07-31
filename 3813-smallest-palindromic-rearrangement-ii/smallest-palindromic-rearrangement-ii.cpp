class Solution {
public:
    // FIX 1: Change k to long long
    long long ncr(int n, int r, long long k) { 
        if (r < 0 || r > n) return 0;
        
        // FIX 2: Ensure strictly increasing intermediate values
        r = min(r, n - r); 
        
        // FIX 3: Use __int128_t to prevent overflow during multiplication
        __int128_t ans = 1; 
        for(int i = 1; i <= r; i++) {
            ans *= (n - i + 1);
            ans /= i;
            if(ans >= k) {
                return k;
            }
        }
        return (long long)ans;
    }

    string smallestPalindrome(string s, long long k) {
        map<char, int> mp;
        for (char c : s) mp[c]++;

        int oddCount = 0;
        char mid = '#';
        string half = "";

        for (auto &p : mp) {
            if (p.second % 2) {
                oddCount++;
                mid = p.first;
                p.second--;
            }
            half += string(p.second / 2, p.first);
        }

        if (oddCount > 1) return "";

        int m = half.size();
        vector<int> freq(26, 0);
        for (char c : half) {
            freq[c - 'a']++;
        }
        
        long long temp = 1; 
        int letters = 0;
        for(int j = 0; j < 26; j++) {
            letters += freq[j];
        }

        for(int j = 0; j < 26; j++) {
            if(freq[j] > 0) {
                long long comb = ncr(letters, freq[j], k);
                if (k / temp < comb) {
                    temp = k + 1;
                    break;
                }
                temp *= comb;
                letters -= freq[j];
            }
        }

        if(temp < k) return "";

        string left = "";

        for (int pos = 0; pos < m; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (freq[ch] == 0) continue;

                freq[ch]--;
                long long ways = 1; 
                int current_letters = 0;
                
                for(int j = 0; j < 26; j++) {
                    current_letters += freq[j];
                }

                for(int j = 0; j < 26; j++) {
                    if (freq[j] > 0) {
                        long long comb = ncr(current_letters, freq[j], k);
                        if (k / ways < comb) { 
                            ways = k + 1; 
                            break; 
                        }
                        ways *= comb;
                        current_letters -= freq[j];
                    }
                }

                if (ways >= k) {
                    left += char(ch + 'a');
                    break;
                } else {
                    k -= ways;
                    freq[ch]++; 
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid == '#')
            return left + right;
        else
            return left + mid + right;
    }
};