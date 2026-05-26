class Solution {
public:

    bool isValid(int len, vector<int>& nums)
    {
        if(len <= 0 || len > nums.size())
            return false;

        const long long base = 31;
        const long long mod = 1e9 + 7;

        unordered_map<long long,int> m;

        long long hash = 0;
        long long power = 1;

        for(int i = 1; i < len; i++)
        {
            power = (power * base) % mod;
        }

        for(int i = 0; i < len; i++)
        {
            hash = (hash * base + nums[i]) % mod;
        }

        m[hash]++;

        for(int i = len; i < nums.size(); i++)
        {
            hash = (
                hash
                - (nums[i-len] * power) % mod
                + mod
            ) % mod;

            hash = (hash * base + nums[i]) % mod;

            m[hash]++;
        }

        for(auto &i : m)
        {
            if(i.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=n;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(isValid(m,nums))
            {
                ans=min(ans,m);
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};