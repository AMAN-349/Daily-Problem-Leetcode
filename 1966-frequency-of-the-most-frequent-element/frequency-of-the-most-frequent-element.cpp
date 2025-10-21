class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> m;
        for (auto x : nums) m[x]++;

        int ans = 0;

        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            int target = it->first;   
            int cnt = it->second;     
            int ops = k;

            for (auto jt = next(it); jt != m.rend() && ops > 0; ++jt) {
                long long val = jt->first;
                long long freq = jt->second;
                long long diff = target - val;

                if (diff * freq <= ops) {
                    ops -= diff * freq;
                    cnt += freq;
                } else {
                    cnt += ops / diff;
                    ops = 0;
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
