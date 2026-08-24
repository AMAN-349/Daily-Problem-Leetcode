class Solution {
public:
    int target, rg;
    vector<int> dp;

    bool find(int n, int mask)
    {
        if(dp[mask] != -1)
            return dp[mask];

        for(int i = 1; i <= rg; i++)
        {
            if(mask & (1 << (i-1)))
                continue;

            if(i >= n)
                return dp[mask] = true;

            int newMask = mask | (1 << (i-1));

            if(!find(n-i, newMask))
                return dp[mask] = true;
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        rg = maxChoosableInteger;
        target = desiredTotal;

        if(desiredTotal == 0)
            return true;

        long long total = 1LL * rg * (rg + 1) / 2;

        if(total < desiredTotal)
            return false;

        dp.assign(1 << rg, -1);

        return find(target, 0);
    }
};