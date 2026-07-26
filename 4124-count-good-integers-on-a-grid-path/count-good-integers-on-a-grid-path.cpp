class Solution {
public:
    vector<int> path;
    long long dp[17][2][8][11];
    bool vis[17][2][8][11];

    long long find(int ind, bool tight, int cnt, int prev, string &s)
    {
        if (ind == 16)
            return 1;

        if (dp[ind][tight][cnt][prev + 1]!=-1)
            return dp[ind][tight][cnt][prev + 1];


        int ub = tight ? (s[ind] - '0') : 9;

        long long ans = 0;

        for (int d = 0; d <= ub; d++)
        {
            bool ntight = tight && (d == ub);

            if (cnt < 7 && path[cnt] == ind)
            {
                if (d >= prev)
                {
                    ans += find(ind + 1, ntight, cnt + 1, d, s);
                }
            }
            else
            {
                ans += find(ind + 1, ntight, cnt, prev, s);
            }
        }

        return dp[ind][tight][cnt][prev + 1] = ans;
    }

    long long solve(long long x)
    {
        if (x < 0) return 0;

        string s = to_string(x);

        while (s.size() < 16)
            s = '0' + s;

        memset(dp, -1, sizeof(dp));

        return find(0, 1, 0, -1, s);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions)
    {
        path.clear();

        int row = 0, col = 0;
        path.push_back(0);

        for (char ch : directions)
        {
            if (ch == 'R')
                col++;
            else
                row++;

            path.push_back(row * 4 + col);
        }

        return solve(r) - solve(l - 1);
    }
};