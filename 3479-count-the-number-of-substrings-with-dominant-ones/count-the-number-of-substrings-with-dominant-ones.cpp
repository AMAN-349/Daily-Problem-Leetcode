class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> pref(n);
        pref[0] = (s[0] == '1');

        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + (s[i] == '1');
        }

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {
                int cnt1 = pref[j] - (i > 0 ? pref[i-1] : 0);
                int cnt0 = (j - i + 1) - cnt1;

                long long z2 = 1LL * cnt0 * cnt0;

                if (z2 > cnt1) {
                    int skip = z2 - cnt1;
                    j += skip - 1;
                }
                else if (z2 == cnt1) {
                    ans++;
                }
                else { 
                    ans++;
                    int k = (int)sqrt(cnt1) - cnt0;
                    int next = j + k;

                    if(next >= n) {
                        ans += (n - j - 1);
                        break;
                    } else {
                        ans += k;
                    }

                    j = next;
                }
            }
        }

        return ans;
    }
};
