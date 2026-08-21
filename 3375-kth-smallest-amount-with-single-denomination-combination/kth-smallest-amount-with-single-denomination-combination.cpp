class Solution {
public:
    int n;

    long long LCM(long long a, long long b)
    {
        return (a / __gcd(a, b)) * b;
    }

    long long isposs(vector<int>& arr, long long val)
    {
        long long ans = 0;

        for(int mask = 1; mask < (1 << n); mask++)
        {
            long long lcm = 1;
            int bits = 0;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    bits++;
                    lcm = LCM(lcm, (long long)arr[i]);

                    if(lcm > val)
                        break;
                }
            }

            if(lcm > val)
                continue;

            long long cnt = val / lcm;

            if(bits % 2)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        n = coins.size();

        long long l = *min_element(coins.begin(), coins.end());
        long long r = l * k;

        while(l <= r)
        {
            long long m = l + (r - l) / 2;

            long long total = isposs(coins, m);

            if(total >= k)
                r = m - 1;
            else
                l = m + 1;
        }

        return l;
    }
};