class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        int ind = -1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0) ind = i;
        }

        if (ind == -1) return 0;
        if (sum < 0) return -1;

        long long need = -balance[ind];
        vector<pair<long long, long long>> pos;

        for (int i = 0; i < n; i++) {
            if (balance[i] > 0) {
                long long dist = min(
                    abs(i - ind),
                    n - abs(i - ind)
                );
                pos.push_back({dist, balance[i]});
            }
        }

        sort(pos.begin(), pos.end());

        long long ans = 0;

        for (auto &[dist, val] : pos) {
            if (need == 0) break;
            long long take = min(need, val);
            ans += take * dist;
            need -= take;
        }

        return (need == 0 ? ans : -1);
    }
};
