class Solution {
public:

    bool check(long long m, vector<int>& d, vector<int>& r)
    {
        long long first = m - m / r[0];
        long long second = m - m / r[1];

        __int128 lcm = (__int128)r[0] * r[1] / __gcd(r[0], r[1]);
        long long common = m - m / (long long)lcm;

        return first >= d[0] && second >= d[1] && common >= d[0] + d[1];
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low = d[0] + d[1];
        long long high = 1e18;
        long long ans = high;

        while(low <= high) {
            long long mid = (low + high) / 2;
            if(check(mid, d, r)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
