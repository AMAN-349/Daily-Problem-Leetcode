class Solution {
public:

    int find(int st, int e, vector<int>& nums)
    {
        int ans = nums[st];
        for (int i = st; i <= e; i++)
        {
            ans = __gcd(ans, nums[i]);
        }
        return ans;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        pair<int, int> res = {-1, -1};

        while (j < n)
        {
            int g = find(i, j, nums);
            while (g == 1 && i < j)
            {
                int g2 = find(i + 1, j, nums);
                if (g2 == 1)
                    i++;
                else
                    break;
                g = g2;
            }

            if (g == 1)
            {
                if (res.first == -1 || (j - i) < (res.second - res.first))
                {
                    res.first = i;
                    res.second = j;
                }
            }

            j++;
        }

        if (res.first == -1 && res.second == -1)
        {
            return -1;
        }

        if (res.first == res.second)
        {
            int cnt = 0;
            for (auto x : nums)
            {
                if (x != 1)
                    cnt++;
            }
            return cnt;
        }

        int fans = (res.second - res.first) + (n - 1);
        return fans;
    }
};
